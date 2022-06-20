//! A class static variable's lifetime lasts for the complete duration of the program, 
//! like global variables.
class Coordinates {

    // Data member
    float latitude_ = 0;

    // Data member
    float longitude_ = 0; 

    //Constructor
    Coordinates (float lati, float longi){
        latitude_ = lati;
        longitude_ = longi;
    }

public:
  //! Static data member declaration
  static const Coordinates hearthCenter;

  // Member function declaration
  float distanceFrom(Coordinates other);

  // Member function definition
  float distanceFromCenter() {
    return distanceFrom(hearthCenter);
  }
};

//! Static data member definition
const Coordinates Coordinates::hearthCenter = Coordinates(0, 0);
//! When accessing a static member, we might not have an instance to use the dot operator on. 
//! C++ gives us the ability to access the static members of a class by using the scope 
//! resolution operator, which is, a double colon (::), after the class name.