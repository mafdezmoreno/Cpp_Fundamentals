//! Modifications based on:
// https://www.geeksforgeeks.org/move-constructors-in-c-with-examples/
// https://en.cppreference.com/w/cpp/language/move_assignment
// https://www.codementor.io/@sandesh87/the-rule-of-five-in-c-1xpdgpzb04f
// https://www.codementor.io/@sandesh87/the-rule-of-five-in-c-1pdgpzb04f

#include <iostream>

struct MovableClass {

		int* data;
		int id;
	
		MovableClass() { //Constructor
			std::cout << "Def. construct " << this << std::endl;
			data = new int(111);
		}

		//! Move constructor
		MovableClass(MovableClass&& other): data (std::move(other.data)) {
			std::cout << "Move construct " << this << std::endl;
			//!variables:
			id = other.id;
			//!pointers:
			data = other.data;
			other.data = nullptr;
		}

		//!Move assignment 
		MovableClass& operator=(MovableClass&& other) {
			if (this != &other){ //To prevent auto assignment
				std::cout << "Move assign " << this << std::endl;

				//!variables:
				id = other.id;

				//!pointers:				
				// Delete old pointer:
				if (data){
					delete data;
				}
				data = other.data;
				other.data = nullptr;
				
			}
			return *this;
		}

		~MovableClass() {
			std::cout << "Destructor " << this; //<< std::endl;

			//To be sure allocated memory is liberated:
			if (data != nullptr){
				// If the pointer is not
				// pointing to nullptr
				std::cout << " is called for "
					<< *data << " " << data << std::endl;
			}
			else{
				std::cout << " is called for nullptr "
					<< std::endl;
			}
		}
};

int main(){
    
	//Def. construct
    MovableClass first;
    std::cout << "  -> First:  " << &first << "\tdata: " << *first.data<< " "<< first.data <<std::endl;
	
	// Move construct
	MovableClass second = std::move(first);
    // Or: MovableClass second(std::move(first));
	std::cout << "  -> First:  " << &first << "\tdata: " << "null"<< " " << first.data <<std::endl;
    std::cout << "  -> Second: " << &second << "\tdata: " << *second.data<< " "<< second.data <<std::endl;

	//Def. construct
	MovableClass third;
    std::cout << &third <<std::endl;
	std::cout << "  -> Third:  " << &third << "\tdata: " << *third.data<< " " << third.data <<std::endl;
	// Move assignment
    second = std::move(third);
	std::cout << &second <<std::endl;
	std::cout << "  -> Third:  " << &third << "\tdata: " << "null" << " " << third.data <<std::endl;
	std::cout << "  -> Second: " << &second << "\tdata: " << *second.data<< " " << second.data <<std::endl;

	std::cout << "\nChecking that instances have move the memory positions:" << std::endl;
    std::cout << &first <<std::endl;
    std::cout << &second <<std::endl;
    std::cout << &third <<std::endl;
	std::cout << std::endl;
	return 0;
}