#include <iostream>
#include <set>
#include <functional>
#include <map>


/* ////! Associative Containers

    * Set: Element are ordered and with distinct values.
    * Multiset: Element duplicated are allowed.
    * Map: Mapped by key values. Ordered by keys (which can't be repeated)
    * Multimap: Keys can be duplicated

    ////! Principal characteristic:
    * Optimized for element lookup: Set and Multiset
*/

void printMapResult(std::map<int, std::string> & m, int k);

int main() {
    //! Set (& multiset) (ordered by elements)
    std::cout << "\nSET" << std::endl;
    std::set<int> ascending = {5,8,4,2,1};
    std::cout << "Ascending numbers:";
    for(int number : ascending) {
        std::cout << " " << number;
    }
    std::cout << std::endl;
    
    std::set<int, std::greater<int>> descending = {5,3,9,2,1};
    std::cout << "Descending numbers:";
    for(int number : descending) {
        std::cout << " " << number;
    }
    std::cout << std::endl;

    //! Map (& multimap)
    // Map allows you to associate a single value to a key, while multimap allows 
    // you to associate multiple values to the same key.
    std::cout << "\nMAP" << std::endl;
    std::map<int, std::string> map;
    map.insert(std::make_pair(1, "1"));
    map.insert(std::make_pair(4, "4"));
    map.insert(std::make_pair(8, "8"));
    std::cout << "The key 4 contents: " << map[4] <<std::endl;
    std::cout << "The key 8 contents: " << map.at(8) <<std::endl;
    printMapResult(map, 4);
    printMapResult(map, 3);
}

void printMapResult(std::map<int, std::string> & m, int k){
    auto position = m.find(k);
    if (position != m.end() ) {
        std::cout << "Found! The key is " 
            << position->first << ", the value is: \"" 
            << position->second << "\""<< std::endl;
    }
    else{
        std::cout << "Key not found" <<std::endl;
    }
}