//! Sorting Algorithms
/*
    * sort
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vector = {5, 2, 6, 4, 3, 1};
    
    std::sort(vector.begin(), vector.end());
    std::cout << "Values: ";
    std::for_each(vector.begin(), vector.end(), [](int value) 
    { 
        std::cout << value << " "; 
    });
    std::cout << std::endl;
}