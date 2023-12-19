// Section 20
// Algorithms
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<cctype>

class Person {
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age) : name(name), age(age) {}
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

// Find an element in a container
void find_test() {
    std::cout << "\n=========================" << std::endl;
    std::vector<int> vec{1,2,3,4,5};

    auto loc = std::find(std::begin(vec), std::end(vec), 1);

    if (loc != std::end(vec))
        std::cout << "Found the number: " << *loc << std::endl;
    else
        std::cout << "Coundn't find the number" << std::endl;
    
    std::list<Person> players {
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21}
    };

    auto loc1 = std::find(players.begin(), players.end(), Person{"Moe", 20});
    if (loc1 != players.end())
        std::cout << "Found Moe " << *loc << std::endl;
    else
        std::cout << "Coundn't find Moe" << std::endl;
}

// Count the number of elements in a container
void count_test() {
    std::cout << "\n=====================" << std::endl;

    std::vector<int> vec{1,2,3,4,5};

    int num = std::count(vec.begin(), vec.end(), 1);
    std::cout << num << " occurrences found" << std::endl;
}

// Count only if the element is even
void count_if_test() {
    std::vector<int> vec{1,2,3,4,5,1,2,1,100};
    int num = std::count_if(vec.begin(), vec.end(), [](int x){return x % 2 == 0;});
    std::cout << num << " even numbers fuound" << std::endl;

    int num1 = std::count_if(vec.begin(), vec.end(), [](int x){return x % 2 != 0;});
    std::cout << num1 << " odd numbers fuound" << std::endl;   

    // how can we determine how many elements in vec are >= 5?
    int num2 = std::count_if(vec.begin(), vec.end(), [](int x){return x >= 5;});
    std::cout << num2 << " numbers are > 5" << std::endl;   
}

// Replace occurrences of elements in a container
void replace_test() {
    std::cout << "\n=====================" << std::endl;

    std::vector<int> vec{1,2,3,4,5,1,2,1};
    for (auto i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::replace(vec.begin(), vec.end(), 1, 100);
    for (auto i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void all_of_test() {
    std::vector<int> vec1{1,2,4,7,9,23,34,23};
    if (std::all_of(vec1.begin(), vec1.end(), [](int x){return x >10;}))
        std::cout << "All the elements are > 10" << std::endl;
    else
        std::cout << "Not all the elements are > 10" << std::endl;

    if (std::all_of(vec1.begin(), vec1.end(), [](int x){return x < 50;}))
        std::cout << "All the elements are < 50" << std::endl;
    else
        std::cout << "Not all the elements are < 50" << std::endl;
}

// Transform elements in a container - string in this example
void string_transform_test() {
    std::cout << "\n==============" << std::endl;

    std::string str1 {"This is a test"};
    std::cout << "Before transform: " << str1 << std::endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    std::cout << "After transform: " << str1 << std::endl;
}

int main() {
    // all_of_test();
    string_transform_test();

    return 0;
}