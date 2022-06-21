#include <iostream>

//! Example of bad Dynamic Memory Use:

class Logger{
	public:
		std::string data;
		Logger(){
			std::cout << "Constructor Called " << this << std::endl;
		}
		Logger(const std::string &s){
			data = s;
		}
		~Logger(){
			std::cout << "Destructor Called " << this << std::endl;
		}
};

class TestLogger: public Logger{
	public:
		TestLogger(const std::string &s){
			data = s + " T";
		}
		~TestLogger(){
			std::cout << "Destructor Called T" << this << std::endl;
		}
};

class ReleaseLogger: public Logger{
	public:
		ReleaseLogger(const std::string &s){
				data = s + " R";
			}
		~ReleaseLogger(){
			std::cout << "Destructor Called R" << this << std::endl;
		}
};

bool are_test_running();
Logger* createLogger();
void myOperation(Logger * L, int index);

int main(){

    Logger * logger = createLogger();
    myOperation(logger, 2);
    delete logger;

	//! Warning:
	// There is no call to delete inside myOperation! This means that the code 
	// calling the createLogger function needs to make sure to call #delete#.

    return 0;
}

Logger* createLogger() {

	if (are_test_running()) {
		TestLogger* logger = new TestLogger("Init");
		return static_cast<Logger*>(logger);
	} else {
		ReleaseLogger* logger = new ReleaseLogger(std::move("Release logger"));
		return static_cast<Logger*>(logger);
    }
}

bool are_test_running(){
    //return true;
	return false;
}

void myOperation(Logger * L, int index){
    std::cout << L->data << " " <<  index << std::endl;
}