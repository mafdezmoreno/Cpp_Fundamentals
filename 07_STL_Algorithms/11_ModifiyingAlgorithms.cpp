#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<std::string> vector = {"Hello", "C++", "Morning", "Learning"};
    std::vector<std::string> longWords;
    
    //! copy_if
    std::cout << "\ncopy_if" << std::endl;
    std::copy_if(vector.begin(), vector.end(), std::back_inserter(longWords), 
        [](const std::string& s) { return s.length() > 3; });
    std::cout << "Number of longWords: " << longWords.size() << std::endl;
    
    //! transform & for_each
    std::cout << "\ntransform" << std::endl;
    std::vector<int> lengths;
    std::transform(longWords.begin(), longWords.end(), std::back_inserter(lengths), 
        [](const std::string& s) { return s.length(); });
    std::cout << "\tLengths: ";
    std::for_each(lengths.begin(), lengths.end(), [](int length) { 
        std::cout << length << " "; });
    std::cout << std::endl;
    
    //! remove_if & erase
    auto newLast = std::remove_if(lengths.begin(), lengths.end(), 
        [](int length) { return length < 7; });
    std::cout << "No element removed yet: " << lengths.size() << std::endl;
    // erase all the elements between the two iterators
    lengths.erase(newLast, lengths.end());
    std::cout << "Elements are removed now. Content: ";
    std::for_each(lengths.begin(), lengths.end(), [](int length) {
         std::cout << length << " "; });
    std::cout << std::endl;
}