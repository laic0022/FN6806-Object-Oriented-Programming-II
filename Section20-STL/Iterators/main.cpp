#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<list>

void display(const std::vector<int> &vec) {
    std::cout << "[";
    for (auto const &i: vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\n===============================" << std::endl;
    std::vector<int> nums1{1,2,3,4,5};

    auto it = nums1.begin();
    std::cout << *it << std::endl;

    it++;
    std::cout << *it << std::endl;

    it += 2;
    std::cout << *it << std::endl;

    it -= 2;
    std::cout << *it << std::endl;

    it = nums1.end() - 1;
    std::cout << *it << std::endl;

}

void test2() {
    std::cout << "\n===============================" << std::endl;
    std::vector<int> nums1{1,2,3,4,5};

    std::vector<int>::iterator it = nums1.begin();
    while (it != nums1.end()) {
        std::cout << *it << std::endl;
        it++;
    }

    it = nums1.begin();
    while(it != nums1.end()) {
        *it = 0;
        it++;
    }
    display(nums1);
}

void test3() {
    std::cout << "\n===============================" << std::endl;
    std::vector<int> nums1{1,2,3,4,5};
    std::vector<int>::const_iterator it1 = nums1.begin();
    // auto it1 = nums1.cbegin();

    while (it1 != nums1.end()) {
        std::cout << *it1 << std::endl;
        it1++;
    }

    it1 = nums1.begin();
    while(it1 != nums1.end()) {
        // *it1 = 0; complie error
        it1++;
    }
}

void test4() {
    std::vector<int> vec{1,2,3,4};
    auto it1 = vec.rbegin();
    while (it1 != vec.rend()) {
        std::cout << *it1 << std::endl;
        it1++;
    }

    // const reverse iterator over a list
    std::list<std::string> name{"Larry", "Moe", "Curly"};
    auto it2 = name.crbegin(); // iterator over list of strings point to Curly
    std::cout << *it2 << std::endl;
    it2++; // point to Moe'
    std::cout << *it2 << std::endl;

    // iterator over a map
    std::map <std::string, std::string> favorites {
        {"Frank", "C++"},
        {"Bill", "Java"},
        {"James", "Haskell"}
    };
    auto it3 = favorites.begin();
    while (it3 != favorites.end()) {
        std::cout << it3->first << " : " << it3->second << std::endl;
        it3++;
    }

}  

void test5() {
    // iterate over a subset of a container
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    auto start = vec.begin() + 2;
    auto finish = vec.end() - 3;

    while (start != finish) {
        std::cout << *start << std::endl;
        start++;
    }
}
int main() {
    // test1();
    test5();

    return 0;
}