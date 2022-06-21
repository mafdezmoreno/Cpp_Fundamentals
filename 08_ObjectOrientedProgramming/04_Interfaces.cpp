#include <iostream>

//! Interfaces
/*
Functions and methods which accepts parameters as interface are a way of saying: 
in order to perform my actions, I need these functionalities; it's up to you to 
provide them
*/

//! Abstract Vehicle Class
/*
Any class that defines a pure virtual method is abstract. A pure virtual method 
is a virtual method that ends with = 0
*/

//! Abstract Vehicle Class. Guidelines:
/*
    * should not have any data members or fields
    * should always define a virtual destructor
    * All the methods should be:
        * pure virtual
        * public
        * keep single functionality
    * Disable copy and move constructors and assig. operators (slicing problem).
*/

//Abstract class
class Vehicle {
	public:
		virtual void turnOn() = 0; //! Pure virtual method

		Vehicle(){
			std::cout << "Vehicle constructor " << this << std::endl;
		}

		//Guidelines:
		Vehicle(const Vehicle&) = delete;
		Vehicle& operator=(const Vehicle&) = delete;
		Vehicle(Vehicle&&) = delete;
		Vehicle& operator=(Vehicle&&) = delete;
		~Vehicle() = default;
};

//Abstract class (derived from abstract class)
class GasolineVehicle: public Vehicle {
	public:
		virtual void fillTank() = 0; //! Pure virtual method

		GasolineVehicle(){
			std::cout << "Constructor Gasoline Vehicle " << this << std::endl;
		}

		//Guidelines:
		GasolineVehicle(const GasolineVehicle&) = delete;
		GasolineVehicle& operator=(const GasolineVehicle&) = delete;
		GasolineVehicle(GasolineVehicle&&) = delete;
		GasolineVehicle& operator=(GasolineVehicle&&) = delete;
		~GasolineVehicle() = default;
};

//Concrete class. This can be instantiated
class Car : public GasolineVehicle {
    
	public:
		virtual void turnOn() override;
		virtual void fillTank() override;

		Car(){
			std::cout << "Car constructor " << this <<std::endl;
		};
		//Guidelines:
		Car(const Car&) = delete;
		Car& operator=(const Car&) = delete;
		Car(Car&&) = delete;
		Car& operator=(Car&&) = delete;
		~Car() = default;
};

void Car::turnOn(){
    std::cout << "\tTurning On Car" <<std::endl;
}

void Car::fillTank(){
    std::cout << "\tFilling Tank " << std::endl;
}


int main(){
    
    Car c;
    c.fillTank();
    c.turnOn();

    return 0;
}