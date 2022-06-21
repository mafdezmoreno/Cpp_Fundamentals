#include <iostream>
#include <memory> //!pointers

//! Example of Safe Dynamic Memory Use:

class Logger{
	public:
		std::string data;
		Logger(){
			std::cout << "Constructor Called L " << this << std::endl;
			data = data + "Empty ";
		}
		Logger(const std::string &s){
			data = s;
		}
		~Logger(){
			std::cout << "Destructor Called L " << this << std::endl;
		}
};

class TestLogger: public Logger{
	public:
		TestLogger(const std::string &s){
			data = data + s + " T ";
		}
		~TestLogger(){
			std::cout << "Destructor Called T" << this << std::endl;
		}
};

class ReleaseLogger: public Logger{
	public:
		ReleaseLogger(const std::string &s){
				data = data +  s + " R ";
			}
		~ReleaseLogger(){
			std::cout << "Destructor Called R" << this << std::endl;
		}
};

bool are_test_running();
std::unique_ptr<Logger>createLogger();
void myOperation(std::unique_ptr<Logger> & L, int index);

int main(){

	std::unique_ptr<Logger> logger = createLogger();
    myOperation(logger, 2);
    //delete logger; //!We don't need this now
    return 0;
}

std::unique_ptr<Logger>createLogger() {

	if (are_test_running()) {
		//!before: TestLogger* logger = new TestLogger("Init");
    	std::unique_ptr<ReleaseLogger> logger = std::make_unique<ReleaseLogger>("Release logger");
		return logger; //logger is implicitly moved (no need of move())

	} else {
		// Also, in a short way:
    	return std::move(std::make_unique<TestLogger>("Init"));
		//! the pointer is implicitly moved (no need of move())
    }
}

bool are_test_running(){
    //return true;
	return false;
}

void myOperation(std::unique_ptr<Logger> & L, int index){
    std::cout << L->data << " " <<  index << std::endl;
}