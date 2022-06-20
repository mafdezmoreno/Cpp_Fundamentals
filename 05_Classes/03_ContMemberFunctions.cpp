#include <iostream>
#include <string>

class Car
{
  public:
    std::string& getColor() {
      std::cout<< "non-const" << std::endl;
    }

    //!Member function declared as a const 
    const std::string& getColor() const {
          std::cout<< "const" << std::endl;
    } 
    //!getColor overload:
      // The const member function will be called when an object is declared const
      // The NON-const function is called when an object is declared NON-const

    //! Three version of const member functions:
    int& function1() const {} // const member function

    const int& function2() {} //returns a const reference

    const int& function3() const {} //const function that returns a const reference
};

int main(){

  Car car;
  // Call std::string& getColor()
  car.getColor();

  const Car constCar; 
  // Call const Color& getColor() const
  constCar.getColor();

  return 0;
}
