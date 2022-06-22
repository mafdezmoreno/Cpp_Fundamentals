
//! Lambda

#include <iostream>

int main()
{
    auto sum_numbers1 = [] (int a, int b) { return a + b; };
    std::cout << sum_numbers1(10, 20) << std::endl;

    int addend = 1;
    auto sum_numbers2 = [addend](int b) { return addend + b; };
    addend = 2; //! The function store the previous value
    std::cout << sum_numbers2(3) << std::endl;

    int * toSum = &addend;
    auto sum_numbers3 = [toSum](int b) { return *toSum + b; };
    addend = 2; //! The function get this value because the input is a pointer
    std::cout << sum_numbers3(3) << std::endl;
}
