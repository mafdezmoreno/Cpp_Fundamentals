//! Numeric Algorithm
/*
    * accumulate
*/

#include <iostream>
#include <vector>
#include <numeric> //accumulate

int main()
{
    std::vector<int> vector = {1, 2, 3, 4, 5, 6};

    int initial_value = 0;
    int accumulated = std::accumulate(vector.begin(), vector.end(), initial_value);
    std::cout << "Accumulate: " << accumulated << std::endl;
}