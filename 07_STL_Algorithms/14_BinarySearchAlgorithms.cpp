//! Binary search
/*
    * binary_search
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vector = {1, 2, 3, 4, 5, 6};
    
    bool found = std::binary_search(vector.begin(), vector.end(), 2);
    std::cout << "Found: " << found << std::endl;
}