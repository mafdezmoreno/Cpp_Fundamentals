
//! Iterators
/*
    * Input iterators are usually used in a pattern where access to elements 
    * is always followed by a position increment.
        * provide the == and != operators to check if is equal to the end()
        * Only one pass.
    
    * Forward iterators: more features.
        * if we make a copy of a forward iterator, we can advance the first one, 
        * and the second can still be used to access the previous element
    
    * Bidirectional iterators.  operator-- &  operator++
    
    * Random-access iterators are also bidirectional iterators with the additional 
    * ability to directly access any position without the need of a linear scan, in 
    * constant time. 
        * operator[], operator+ and operator-
*/

#include <iostream>
#include <vector>

int main(){

    //! /Iterators
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    for (auto it = numbers.begin(); it!=numbers.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    //! Reverse Iterators

    for(auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
        std::cout << *rit << " "; 
    }
    std::cout << std::endl;
    
    return 0;
}