#include <iostream>
#include <string>

class C;

struct A {

    int id = 0;
    int * pointer_a;
    A(){
        std::cout << "Default Construct A " << this << std::endl;
    }

    A(const A& a) {
        std::cout << "Copy construct A "<< this << std::endl;
    }
    void print_id(){
        std::cout << this << std::endl;
    }
};

struct B {
    int _id = 0;
    B() {
        std::cout << "Default Construct B " << this << std::endl;
    }

    B(const B& a) {
        std::cout << "Copy construct B " << this << std::endl;
    }
    void print_id(){
        std::cout << this << std::endl;
    }
};

class C {

  public:
    int * pointer_test;
    A a;
    B b;
    //! The copy constructor is implicitly generated

    void print_id(){
      std::cout << this << std::endl;
    }
};

int main() {

  C first;
  
  first.a.id = 111;
  std::cout << "\nThe id value config in first.a is:" << std::endl;
  std::cout << "\t" << first.a.id << std::endl;
  int to_test_pointer_1 = 11;
  int to_test_pointer_2 = 12;
  first.a.pointer_a = &to_test_pointer_1;
  first.pointer_test = &to_test_pointer_2;
  
  // Because the copy constructor of A and B is implicitly generated, first is copied
  // to second
  C second(first);
  // Prints: "Copy construct A", "Copy construct B"

  second.a.id = 111;
  std::cout << "\nThe id value copied form first.a into second.a is:" << std::endl;
  std::cout << "\t" << second.a.id << std::endl;

  //! To check that the objects have been copied:
  // The second object have different direction for fist (but C and A classes has 
  // the same memory position (both start at the same position)))
  
  std::cout << "\nMemory position of first object" << std::endl;
  first.print_id();
  first.a.print_id();
  first.b.print_id();
  
  std::cout << "\nMemory position of second object" << std::endl;
  second.print_id();
  second.a.print_id();
  second.b.print_id();

  //! Warning:
  /*
  When a pointer is copied, we are not copying the object pointed to, but simply 
  the address at which the object is located.

  This means that when a class contains a pointer as a data member, the implicit 
  ////!copy constructor only copies the pointer and not the pointed object, so the 
  copied object and the original one will share the object that's pointed to by 
  the pointer. //!This is sometimes called a shallow copy.
  */

  std::cout << "\nChecking pointer of instance copied: " << std::endl;
  std::cout << "    The pointer inside interior struct in copied (not pointing the same place) (Copy): " << std::endl;
  std::cout << "\t" << first.a.pointer_a << ": " << *first.a.pointer_a << std::endl;
  std::cout << "\t" << second.a.pointer_a << ": "<< *second.a.pointer_a<< std::endl;

  std::cout << "    The pointer inside principal class of instance copied point to the same than original (shallow copy): " << std::endl;
  std::cout << "\t" << first.pointer_test << ": " << *first.pointer_test  << std::endl;
  std::cout << "\t" << second.pointer_test << ": "<< *second.pointer_test<< std::endl;
}
