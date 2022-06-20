#include <iostream>

struct Rectangle {

    int height, width;

    /*
    ////! Constructor no parameter
    Rectangle() {
        height = 0;
        width = 0;
    }*/

    //! Recommended way of initialization (Do the same that previous way):
    Rectangle(): width(0), height(0) { 
        std::cout << "Constructor called " << this << std::endl;
    } //Empty function body, as the variables have already been initialized

    //! Overloaded constructor
    Rectangle(int h, int w) {
        height = h;
        width = w;
        std::cout << "Constructor called " << this << std::endl;

    }

    //! Destructor
    ~Rectangle(){
        std::cout << "Destructor called " << this << std::endl;
    }
};

struct Rectangle2 {

    int height, width;
};

int main(){

    Rectangle r1; //! Use first constructor
    std::cout << "Height: " << r1.height << std::endl; //! Without constructor print random value
    std::cout << "Width: " << r1.width << std::endl;

    Rectangle r2(2,4); //! Use second constructor
    std::cout << "Height: " << r2.height << std::endl;
    std::cout << "Width: " << r2.width << std::endl;

    //! Be careful with hide conversion of variable:
    Rectangle r3((float)2.3,4.5); //! Use second constructor
    std::cout << "Height: " << r3.height << std::endl;
    std::cout << "Width: " << r3.width << std::endl;


    //! Aggregate Classes Initialization
    //! CAN NOT BE USED WITH CLASES THAT ALREADY HAVE CONSTRUCTOR
    //Rectangle rectangle = {10, 15}; //!ERROR
    //std::cout << "Height: " << rectangle.height << std::endl;
    //std::cout << "Width: " << rectangle.width << std::endl;

    //! Whit classes no have constructor:
    Rectangle2 rectangle = {10, 15};
    std::cout << "Height: " << rectangle.height << std::endl;
    std::cout << "Width: " << rectangle.width << std::endl;

    return 0;
}