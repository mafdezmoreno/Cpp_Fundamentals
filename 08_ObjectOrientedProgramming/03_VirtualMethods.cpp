#include <iostream>

// ! Virtual Methods
/*
It is good to be explicit virtual keyword, but if we are already using the 
override keyword, it might be redundant – in these cases, the best way is to 
follow the coding standard of the project you are working on.

The virtual keyword can be applied to any method. Since the constructor is not 
a method, the constructor cannot be marked as virtual. Additionally, dynamic 
dispatch is disabled inside constructors and destructors.
*/

struct A {
  virtual void foo() {
    std::cout << "A's foo" << std::endl;
  }
};

struct B: A {
  virtual void foo() override {
    std::cout << "B's foo" << std::endl;
  }
};

struct C: B {
  virtual void foo() override {
    std::cout << "C's foo" << std::endl;
  }
};

int main() {
    B b;
    C c;
    A* a = &b;

	//! The behaviour seen in the previous program is avoid with virtual specifier
        
    a->foo();  // B::foo() is executed
    a = &c;
    a->foo();
    /* C::foo() is executed, because it's the most derived Class overriding foo(). */
}