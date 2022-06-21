#include <iostream>

//! Polymorphism
//! Dynamic Binding: the ability for a reference or a pointer of a base type 
//! to point to an object of a derived type at RUNTIME

struct A {
	A(){
		std::cout << "\tA " << this <<std::endl;
	}
	void print(){
		std::cout << "Hello from A" << std::endl;
	}
};

struct B: A{
	B(){
		std::cout << "\tB " << this << std::endl;
	}
	void print(){
		std::cout << "Hello from B" << std::endl;
	}
};

struct C: A {
	C(){
		std::cout << "\tC " << this << std::endl;
	}
	void print(){
		std::cout << "Hello from C" << std::endl;
	}
};

int main(){

    std::cout << "Instances creation" <<std::endl;
	std::cout << "B b" <<std::endl;
    B b;
	std::cout << "C c" <<std::endl;
    C c;

	std::cout << "Static references: " << std::endl;
	//! A reference holds the address of an object, but behaves syntactically 
	//! like an object:
	// https://docs.microsoft.com/en-us/cpp/cpp/references-cpp?view=msvc-170

	//We are pointing with the type of the base class
	A& ref1 = b; //! Point to base class
	std::cout << "ref1 = b " << &ref1 << " "<< &b <<std::endl;
	A& ref2 = c;
	std::cout << "ref2 = c " << &ref2 << " "<< &c <<std::endl;
	A* ptr = nullptr;

	//! Testing pointer/references
	std::cout << "\nTesting pointer/references " <<std::endl;

	std::cout << "\nA& ref1 = b " << &ref1 <<std::endl;
	ref1.print();

	B& refb = b; //! Points to derived class
	std::cout << "\nB& refb = b " << &refb <<std::endl;
	refb.print();

	C& refc = c; //! Points to derived class
	std::cout << "\nC& refc = c " << &refc <<std::endl;
	refc.print();

	ptr = &b; //Points to base class
	std::cout << "\nptr = &b" << ptr <<std::endl;
	ptr->print();
  
    ptr = &c; //Points to base class
	std::cout << "\nptr = &c" << ptr <<std::endl;
	ptr->print();

	//Points to derived class
	C* ptrc = nullptr;
	ptrc = &c; 
	std::cout << "\nptrc = &c " << ptrc <<std::endl;
	ptrc->print();

    return 0;
}