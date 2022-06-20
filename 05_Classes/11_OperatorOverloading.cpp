#include <iostream>

//! Operator Overloading Example

class Point
{
    public: 

        // Constructor
        Point(int x, int y): x(x), y(y) {}

        //! Operator "+"
        Point operator+(const Point &other) 
        {
            Point new_point(0,0);
            new_point.x = x + other.x; 
            new_point.y = y + other.y;
            return new_point;
        }
        void print_coordinates(){
            std::cout << this 
                << " coordinates are: (" << x << ", " << y << ")" 
                <<std::endl;
        }
	private:
		int x;
		int y;
};

int main(){

    Point first(1,2);
    first.print_coordinates();
    Point second(3,4);
    second.print_coordinates();
    Point sum = first + second;
    sum.print_coordinates();
    return 0;
}