
//! Variant
// it can store multiple types, with only one present at a time. It also keeps 
// track of which type is currently stored.

#include <iostream>
#include <variant>

int main()
{
	//! Can store only one type
	std::variant<std::string, int> variant1 = 42;
	std::variant<std::string, int> variant2  = "hello";

	//std::cout << std::get<0>(variant1) << std::endl; //!Error: It don't have type std::string (pos 0)
	std::cout << std::get<1>(variant1) << std::endl;
	std::cout << std::get<std::string>(variant2) << std::endl;
	std::cout << std::get<0>(variant2) << std::endl;
}