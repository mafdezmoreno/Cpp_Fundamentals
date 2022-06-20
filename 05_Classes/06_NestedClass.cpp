#include <iostream>

//! we can declare more than just data members and member functions; 
//! we can declare a class inside another class.

//! Nested Classes Useful for:
  //  - We need an object that manages some of the logic of the class. In such cases, 
  //    the nested class is usually private
  //  - When designing the functionality of a class, we want to provide a different 
  //    class, closely related to the original one, which provides part of that 
  //    functionality.

// Declaration
class Coordinate {

  public:
    float x;
    float y;
    // Constructor
    Coordinate(): x(0), y(0) {
      std::cout << "Coordinate " << this << " created" << std::endl;
    };

      struct CoordinateDistance {

        // Constructor
        CoordinateDistance(){
          std::cout << "CoordinateDistance " << this << " created" << std::endl;
        }

        float x = 0;
        float y = 0;
        static float walkingDistance(){
          std::cout << "Distance " << std::endl;
          return 0;
        }
        static float walkingDistance(CoordinateDistance distance){
          std::cout << "Distance distance" << std::endl;
          return 0;
        }
      };
};

int main(){
  // Create an instance of the nested class CoordinateDistance
  Coordinate::CoordinateDistance distance;

  /* Different ways of invoke the static method walkingDistance declared inside the nested class CoordinateDistance */
  Coordinate::CoordinateDistance::walkingDistance();
  Coordinate::CoordinateDistance::walkingDistance(distance); //! overloaded
  distance.walkingDistance();

  return 0;
}