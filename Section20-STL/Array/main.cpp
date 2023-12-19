// Section 20
// std::array
#include<iostream>
#include<array>
#include<algorithm>
#include<numeric>  // for more algorithms like accumulate

// Display the array -- note the size MUST be inclued
// when passing a std::array to a function
void display(const std::array<int, 5> &arr) {
    for (auto &i: arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void test1() {
    std::cout << "\nTest1=======================" << std::endl;
    std::array<int ,5> arr1{1,2,3,4,5};
    std::array<int, 5> arr2;

    display(arr1);
    display(arr2); // Elements are not initialized (contain garbage)

    arr2 = {10,20,30,40,50};
    display(arr1);
    display(arr2);

    std::cout << "Size of arr1 is: " << arr1.size() << std::endl;
    std::cout << "Size of arr2 is: " << arr2.size() << std::endl;

    arr1[0] = 1000;
    arr1.at(1) = 2000;
    display(arr1);

    std::cout << "Front of arr2: " << arr2.front() << std::endl;
    std::cout << "End of arr2: " << arr2.back() << std::endl;

}

void test2() {
    std::cout << "\nTest2=======================" << std::endl;
    std::array<int ,5> arr1{1,2,3,4,5};
    std::array<int, 5> arr2{10,20,30,40,50};

    display(arr1);
    display(arr2);

    arr1.fill(0);
    
    display(arr1);
    display(arr2);

    arr1.swap(arr2);

    display(arr1);
    display(arr2);

}

void test3() {
    std::cout << "\nTest3=======================" << std::endl;
    std::array<int ,5> arr1{1,2,3,4,5};

    int *ptr = arr1.data();
    std::cout << ptr << std::endl;
    *ptr = 10000;
    display(arr1);
}

void test4() {
    std::cout << "\nTest4=======================" << std::endl;
    std::array<int ,5> arr1{1,2,3,4,5};
    display(arr1);

    std::sort(arr1.begin(), arr1.end());
    display(arr1);
}

void test5() {
    std::cout << "\nTest5=======================" << std::endl;
    std::array<int ,5> arr1{1,2,3,4,5}; 
    std::array<int, 5>::iterator min_num = std::min_element(arr1.begin(), arr1.end());
    auto max_num = std::max_element(arr1.begin(), arr1.end());
    std::cout << "min: " << *min_num << " , max: " << *max_num << std::endl;
}

void test6() {
    std::cout << "\nTest6=======================" << std::endl;
    std::array<int ,5> arr1{1,2,3,4,5}; 

    auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
    if (adjacent != arr1.end())
        std::cout << "Adjacent elemetn found with value: " << *adjacent << std::endl;
    else    
        std::cout << "No adjacent elements found" << std::endl;   
}

void test7() {
    std::cout << "\nTest7=======================" << std::endl;
    std::array<int ,5> arr1{1,2,3,4,5};   

    // accumlate is from #include<numeric>
    int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
    std::cout << "Sum of the elements in arr1 is:" << sum << std::endl;
}

void test8() {
    std::cout << "\nTest8=======================" << std::endl;
    std::array<int ,5> arr1{1,2,3,4,5}; 

    int count = std::count(arr1.begin(), arr1.end(), 3);
    std::cout << "Found 3: " << count << " times" << std::endl;  
}

void test9() {
    std::cout << "\nTest9=======================" << std::endl;
    std::array<int ,10> arr1{1,2,3,50,60,70,80,200,300,400}; 
    // find how many numbers are between 10 and 200 -> 50,60,70,80

    int count = std::count_if(arr1.begin(), arr1.end(), [](int x){return x > 10 && x < 200;});
    std::cout << "Found " << count << " matches" << std::endl;

}
int main() {
    test9();

    return 0;
}