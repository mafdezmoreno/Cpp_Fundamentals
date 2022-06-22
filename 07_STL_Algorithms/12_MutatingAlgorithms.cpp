//! Mutating Algorithms:
/*
    * reverse
    * reverse copy
    * shuffle
*/

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> vector = {1, 2, 3, 4, 5, 6};
    
    std::random_device randomDevice;
    std::mt19937 randomNumberGenerator(randomDevice());
    std::shuffle(vector.begin(), vector.end(), randomNumberGenerator);
    
    std::cout << "Values: ";
    std::for_each(vector.begin(), vector.end(), [](int value) 
        { std::cout << value << " "; });
    std::cout << std::endl;
    
    std::cout << "Values in reverse order: ";
    std::reverse(vector.begin(), vector.end());
    std::for_each(vector.begin(), vector.end(), [](int value) 
        { std::cout << value << " "; });
    std::cout << std::endl;
}