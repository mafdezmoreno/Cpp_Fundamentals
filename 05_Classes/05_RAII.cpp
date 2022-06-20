#include <iostream>
#include <string>
#include <fstream>


//! Resource Acquisition Is Initialization

class file_handle {
    private:
        std::ofstream& _stream;
  
    public:

        //!Constructor
        file_handle(std::ofstream& stream, const char* filepath) : _stream(stream) {
        _stream.open(filepath);
        }

        //!Destructor
        ~file_handle {
        _stream.close(); //! RAII Achieved using constructor and destructor
        }

};


int main(){
    std::ofstream stream;
    {
    file_handle myfile(stream, "Some path"); // file is opened
    do_something_with_file(stream);
    }                                        //! file is closed here (using destructor)

    std::ofstream stream;
    {
    stream.open("Some path");    // file is opened
    do_something_with_file(stream);
    stream.close();              // file is closed here
    }

    return 0;
}