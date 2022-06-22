#include <iostream>
#include <vector>
#include <algorithm>

    //! Included in algorithm:
    /*
        * all_of
        * any_off
        * none_off
        * 
        * for_each
        * 
        * count
        * count_if
        * 
        * find
        * find_if
        * find_if_not
    */

int main()
{
    //! all_off
    std::cout << "\nall_off" << std::endl;
    std::vector<int> vector = {1, 2, 3, 4};
    bool allLessThen10 = std::all_of(vector.begin(), 
        vector.end(), [](int value) { return value < 10; });
    std::cout << "\tAll are less than 10: " << allLessThen10 << std::endl;

    //! any_of
    std::cout << "\nany_of" << std::endl;
    bool someAreEven = std::any_of(vector.begin(), 
        vector.end(), [](int value) { return value % 2 == 0; });
    std::cout << "\tSome are even: " << someAreEven << std::endl;

    //! none_of
    std::cout << "\nnone_of" << std::endl;
    bool noneIsNegative = std::none_of(vector.begin(), 
        vector.end(), [](int value) { return value < 0; });
    std::cout << "\tNone is negative: " << noneIsNegative << std::endl;
    
    //! count_if
    std::cout << "\ncount_if" << std::endl;
    std::cout << "\tOdd numbers: " << std::count_if(vector.begin(), 
        vector.end(), [](int value) { return value % 2 == 1; }) << std::endl;
    
    //! count
    std::cout << "1 appear: "
        << std::count(vector.begin(),vector.end(), 1) 
        << " times" << std::endl;
    
    //! find
    std::cout << "\nfind" << std::endl;
    auto position = std::find(vector.begin(), vector.end(), 6);
    std::cout << "\t6 was found: " << (position != vector.end()) << std::endl;

    //! find_if
    std::cout << "\nfind_if" << std::endl;
    auto position2 = std::find_if(vector.begin(), vector.end(), 
        [](int value) { return value != 2; });
    std::cout << "\t" << "The first value different of 2 is in position " << *position2 << std::endl;
    
}