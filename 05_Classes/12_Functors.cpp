#include <iostream>

//! Functors
//! They are particularly useful in places where you can pass a function 
//! object to an algorithmic template that accepts an object with 
//! operator() defined


class logger{
  public:
	logger(){
		std::cout << "Def. Constructor Called " << this << std::endl;
	}
	//!Operator "()"
    void operator()(const std::string &s) {
       std::cout << s << std::endl;
    }
	~logger(){
		std::cout << "Destructor Called " << this << std::endl;
	}
};

int main(){

	logger log;
	log(std::string("Hello world!"));
	log("Keep learning C++");
  	return 0;
}