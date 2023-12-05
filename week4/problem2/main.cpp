#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <iomanip> // For std::boolalpha
using namespace std;

// Class template for Stack
template <class T>
class Stack {
    int _top;
    int max_size;
    vector<T> items;

public:
    Stack();
    Stack(int size);
    inline void push(T item);
    inline void pop();
    inline T top();
    inline int size();
    inline bool is_empty();
};

template <class T>
Stack<T>::Stack() : _top(-1), max_size(100) {
    items.resize(max_size);
}

template <class T>
Stack<T>::Stack(int size) : _top(-1), max_size(size) {
    items.resize(max_size);
}

template <class T>
inline void Stack<T>::push(T item) {
    if (_top < max_size - 1) {
        items[++_top] = item;
    } else {
        cout << "Stack overflow!" << endl;
    }
}

template <class T>
inline void Stack<T>::pop() {
    if (_top >= 0) {
        --_top;
    } else {
        cout << "Stack underflow!" << endl;
    }
}

template <class T>
inline T Stack<T>::top() {
    if (_top >= 0) {
        return items[_top];
    } else {
        throw out_of_range("Stack is empty");
    }
}

template <class T>
inline int Stack<T>::size() {
    return _top + 1;
}

template <class T>
inline bool Stack<T>::is_empty() {
    return _top == -1;
}

// Function to perform DFS on a graph using adjacency list representation
template <class T>
void DFS(const vector<list<T>>& graph, T start) {
    vector<bool> visited(graph.size(), false);
    Stack<T> stack;

    stack.push(start);

    cout << "DFS Order: ";
    while (!stack.is_empty()) {
        T vertex = stack.top();
        stack.pop();

        if (!visited[vertex]) {
            cout << vertex << " ";
            visited[vertex] = true;

            for (const T& neighbor : graph[vertex]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    // Test the default constructor
    Stack<int> stack1;

    // Test the constructor with a specified size
    Stack<int> stack2(10);

    // Test push, pop, top, size, and is_empty functions
    stack1.push(5);
    stack1.push(10);
    stack1.push(15);

    cout << "Top element: " << stack1.top() << endl;
    cout << "Stack size: " << stack1.size() << endl;
    cout << "Is stack empty? " << boolalpha << stack1.is_empty() << endl;

    stack1.pop();
    cout << "Top element after pop: " << stack1.top() << endl;

    // Create an adjacency list for a sample graph
    vector<list<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 5},
        {1},
        {1, 5},
        {2, 4}
    };

    // Perform DFS on the graph starting from vertex 0
    cout << "\nDFS starting from vertex 0:\n";
    DFS(graph, 0);

    return 0;
}
