//Exercise 21: Using Multiple Inheritance to Create a "Welcome to the Community" 
//Message Application

#include <iostream>

class DataScienceDev {
public:
    DataScienceDev(){
        std::cout << "Welcome to the Data Science Developer Community." << std::endl;
        std::cout << this << std::endl;
    }
};

class FutureCppDev {
public:
    FutureCppDev(){
        std::cout << "Welcome to the C++ Developer Community." << std::endl;
        std::cout << this << std::endl;
      }
};

class Student : public DataScienceDev, public FutureCppDev {
    public:
    Student(){
        std::cout << "Student is a Data Developer and C++ Developer." << std::endl;
        std::cout << this << std::endl;
    }
};

/* 
////!Output desired:
Welcome to the Data Science Developer Community.
Welcome to the C++ Developer Community.
Student is a Data Developer and C++ Developer.
*/

int main(){

  Student S1;
  //! As we can see, Student implement the constructor of his base classes
  return 0;
}