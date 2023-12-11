#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Coord {
  double _x;
  double _y;

public:
  Coord() : Coord(0, 0) {}
  inline Coord(double x, double y) : _x(x), _y(y) {}
  inline bool operator==(const Coord &rhs) const {
    return tie(_x, _y) == tie(rhs._x, rhs._y);
  }
  inline double x() const { return _x; }
  inline double y() const { return _y; }
  inline Coord operator+(const Coord &p) const {
    return Coord(_x + p._x, _y + p._y);
  }
  Coord &operator+=(const Coord &rhs) {
    _x += rhs._x;
    _y += rhs._y;
    return *this;
  }
};

ostream &operator<<(ostream &out, const Coord &p) {
  return out << "(" << p.x() << "," << p.y() << ")";
}

class Shape {
protected:
  Coord anchorPoint;

public:
  Shape(const Coord &p) : anchorPoint(p) {}
  virtual ~Shape() = default;
  virtual Shape &move(const Coord &offset) = 0;
  virtual string getType() const = 0;
  Coord getAnchorPoint() const { return anchorPoint; }
};

ostream &operator<<(ostream &out, const Shape &s) {
  out << s.getType() << "@" << s.getAnchorPoint();
  return out;
}

class Rectangle : public Shape {
  double width, height;

public:
  Rectangle(const Coord &p, double w, double h)
      : Shape(p), width(w), height(h) {}
  virtual Rectangle &move(const Coord &offset) override {
    anchorPoint += offset;
    return *this;
  }
  string getType() const override { return "Rectangle"; }

  double getWidth() const { return width; }
  double getHeight() const { return height; }
};

ostream &operator<<(ostream &out, const Rectangle &rect) {
  out << rect.getType() << "@" << rect.getAnchorPoint()
      << " (Width: " << rect.getWidth() << ", Height: " << rect.getHeight()
      << ")";
  return out;
}

class Circle : public Shape {
  double radius;

public:
  Circle(const Coord &p, double r) : Shape(p), radius(r) {}
  virtual Circle &move(const Coord &offset) override {
    anchorPoint += offset;
    return *this;
  }
  string getType() const override { return "Circle"; }

  double getRadius() const { return radius; }
};

ostream &operator<<(ostream &out, const Circle &circle) {
  out << circle.getType() << "@" << circle.getAnchorPoint()
      << " (Radius: " << circle.getRadius() << ")";
  return out;
}

class ShapeCollection : public Shape {
protected:
  vector<unique_ptr<Shape>> elements;

public:
  ShapeCollection() : Shape(Coord(0, 0)) {} // Default constructor
  ShapeCollection(unique_ptr<Shape> S) : Shape(Coord(0, 0)) {
    add(std::move(S));
  }

  ShapeCollection &add(unique_ptr<Shape> S) {
    elements.push_back(std::move(S));
    return *this;
  }
  ShapeCollection &remove(size_t i) {
    if (i < elements.size()) {
      elements.erase(elements.begin() + i);
    }
    return *this;
  }
  inline size_t size() const { return elements.size(); }
  virtual ShapeCollection &move(const Coord &offset) override {
    for (auto &element : elements) {
      element->move(offset);
    }
    return *this;
  }
  const vector<unique_ptr<Shape>> &getElements() const { return elements; }
  string getType() const override { return "ShapeCollection"; }
};

ostream &operator<<(ostream &out, const ShapeCollection &sc) {
  out << sc.getType() << ": [";
  const auto &elements = sc.getElements();
  for (size_t i = 0; i < elements.size(); ++i) {
    out << *elements[i];
    if (i < elements.size() - 1) {
      out << ", ";
    }
  }
  out << "]";
  return out;
}

// Test function for move() in Rectangle and Circle
void testMoveFunction() {
  Rectangle rect(Coord(1, 1), 2, 2);
  Circle circle(Coord(2, 2), 1);

  cout << "Original Rectangle: " << rect << endl;
  cout << "Original Circle: " << circle << endl;

  rect.move(Coord(2, 3));
  circle.move(Coord(2, 3));

  cout << "Moved Rectangle: " << rect << endl;
  cout << "Moved Circle: " << circle << endl;
}

int main() {
  testMoveFunction();

  // Test ShapeCollection
  ShapeCollection collection;
  collection.add(make_unique<Rectangle>(Coord(1, 1), 2, 2))
      .add(make_unique<Circle>(Coord(2, 2), 1));

  cout << "Original ShapeCollection: " << collection << endl;

  collection.move(Coord(2, 3));

  cout << "Moved ShapeCollection: " << collection << endl;

  return 0;
}
