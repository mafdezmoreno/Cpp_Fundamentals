#include <iostream>
#include <cassert>
#include <unistd.h>

//! Passing Arguments and Returning Values
void by_value_age_in_5_years(int age) {
  age += 5;
  std::cout << "Age in 5 years: " << age << std::endl;
  // Prints 100
}

void by_reference_age_in_5_years(int& age) {
  age += 5;
  std::cout << "Age in 5 years: " << age << std::endl;
}

void demo_func_arg_pointer(int * a)
{
    std::cout<< "Inside demo_func_arg_pointer function: " << std::endl;
    *a += 10; //! DO NOT FORGET THE *
    std::cout<< "\ta: "<< a << std::endl;     // a contains the direction
    std::cout<< "\t*a: "<< *a << std::endl;   // *a point to value
}

void test_passing_argument_and_returning_values(){
    std::cout<< "\nPassing Arguments and Returning Values" <<std::endl;

    std::cout<< "\nBy value" <<std::endl;
    {
        int age = 95;
        by_value_age_in_5_years(age);
        //! The value of age IS NOT modified in the function
        std::cout << "Current age: " << age << std::endl;
        // Prints 95

        //by_value_age_in_5_years(&age); //! Not valid conversion

    }
    std::cout<< "\nBy reference" <<std::endl;
    {
        int age = 13;
        by_reference_age_in_5_years(age);
        //! The value of age IS modified in the function
        std::cout << "Current age: " << age << std::endl;
    }

    std::cout<< "\nUsing argument pointers" <<std::endl;
    {
        //! Function argument pointer
        // It's equivalent to pass by reference. The value changes
        int num = 20;
        int * num_pointer = &num;
        std::cout << "Initial values: \n"
            << "num: " << num << "\n"
            << "num_pointer " << num_pointer 
            << std::endl;
        demo_func_arg_pointer(num_pointer);
        //! The value of num IS modified in the function
        std::cout << num << std::endl;
        demo_func_arg_pointer(&num);
        //! The value of num IS modified in the function
        std::cout << num << std::endl;
        std::cout << "The value doesn't change"<<std::endl;
    }
}


void modify_pointer(int* pointer) {
    *pointer = 1;
    pointer = 0;
}

//! Returning Values from Functions
const int& max_by_reference(const int& a, const int& b) {
  if (a > b) {
    std::cout << "\t\treturning from fuction: " << &a <<std::endl;
    return a;
  } else {
    std::cout << "\t\treturning from fuction: " << &b <<std::endl;
    return b;
  }
}

void test_returning_values_functions(){

    std::cout << "\nReturning Values from Functions" <<std::endl;
    {
        //! Returning by value
        std::cout << "\tReturning by value" <<std::endl;
        {
            auto max_by_value = [](const int a, const int b)
            {
                if(a > b) {
                    return a;
                } else {
                    return b;
                }
            };

            assert(max_by_value(2,3) == 3);
            //It is preferable to return by value as it's often easier to understand, easier 
            //to use, and as fast as returning by reference.

            //!How can returning by value be so fast? C++11 introduced the move semantic, which 
            //!allows moving instead of copying the return types when they support the move operation.
        }

        //!Returning by reference
        std::cout << "\tReturning by reference" <<std::endl;
        {
            //const int& max_by_reference(const int& a, const int& b)
            const int& a = max_by_reference(1,2);
            std::cout <<"\t \t" << a <<std::endl;  //! Unsafe. Life of a(=2) ended in assignment
            std::cout <<"\t \t" << &a <<std::endl; //! Unsafe. Life of &a ended in assignment
            //sleep(.5);
            //delete &a; //! To simulate/force error
            //std::cout <<"\t \t" << a <<std::endl;
            //std::cout <<"\t \t" << &a <<std::endl;
            //!WARNING
            //! This means that lifetimes 1 and 2 will stop at the end of the assignment. 
            //But we got a reference to one of them! And we are using it!

            //Accessing an object whose lifetime is terminated is prohibited by C++, and 
            //this will result in an invalid program.

            //!To avoid previous problem:
            std::cout << "\t\tAvoiding Problem Life Time: " << std::endl;
            const int c = 3;
            const int d = 4;
            const int& e = max_by_reference(c,d);
            std::cout <<"\t \t" << e <<std::endl;  //! SAFE. "c" and "d" still lives
            std::cout <<"\t \t" << &e <<std::endl; //! SAFE. "c" and "d" still lives
        }
    }
}

//! Another way of call function
//https://www.geeksforgeeks.org/returning-a-function-pointer-from-a-function-in-c-cpp/
void demo_func_pointer(int& a)
{
    a += 10;
}

void test_calling_function_by_pointer(){
    std::cout<< "\nAnother way of call functions" << std::endl;
    std::cout<< "\nCalling Function By pointer" << std::endl;
    //https://www.geeksforgeeks.org/returning-a-function-pointer-from-a-function-in-c-cpp/
    {
        int num = 20;
        int * num_pointer = &num;
        // Now ptr contains address of demo
        // function or void
        void (*ptr)(int&) = &demo_func_pointer; //! Definition of pointer (prt) to function
    
        //!Calling the function using the pointer
        // or (*ptr)(num);
        ptr(num); //The variable num if passed by reference
        std::cout << num << std::endl; //So the value is modified outside de function
        // or (*ptr)(num);
        (*ptr)(*num_pointer);
        std::cout << num << std::endl;
    }
}

//! Working with const References or r-value References
void test_const_references(){
    std::cout << "\nWorking with const References or r-value References" <<std::endl;

    {


        int a = 3;
        int* ptr = &a;
        std::cout << "Initial value a: " << a << std::endl;
        std::cout << "Initial value ptr: " << ptr << std::endl;
        modify_pointer(ptr);
        std::cout << "Did the pointer change? " 
            << std::boolalpha <<  !(ptr == &a) << std::endl;
        std::cout << "Final value a: " << a << std::endl;
        std::cout << "Final value ptr: " << ptr << std::endl;
        std::cout << "Final value &a:  " << &a << std::endl;


        /* 
        !The pointer can NOT BE MODIFIED in the fuction
        We need to remember that a pointer is a value that represents the location 
        of an object.
        !Being a value, it means that when we are accepting a parameter as a pointer, 
        !the pointer itself is passed as a value.
        !This means that the modification of the pointer inside the function is not 
        !going to be visible to the caller.
        !But if we are modifying the object the pointer points to, then the original 
        !object is going to be modified:
        */
    }
}


//! Const Parameters and Default Arguments
//! Const Return
//https://www.geeksforgeeks.org/const-keyword-in-cpp/
const int const_return(int y)
{
    y--;
    return y;
}

void test_const_return(){
    std::cout << "\nConst Parameters and Default Arguments" << std::endl;
    std::cout << "\nConst Return" << std::endl;
    //https://www.geeksforgeeks.org/const-keyword-in-cpp/
    //The return type of the const_return() is const and so it returns a const integer value to us.
    {
        int x = 9;
        const int z = 10;
        std::cout << "\t" << const_return(x) << '\n'
             << "\t" <<const_return(z) << std::endl;

    }
}

//! Const Return and Const Parameter
const int const_return_and_parameter(const int y)
{
    // y = 9; //it'll give CTE error as
    // y is const var its value can't
    // be change
    return y;
}

void test_const_return_and_parameter(){
    
    std::cout << "\nConst Return and Const Parameter" << std::endl;
    //https://www.geeksforgeeks.org/const-keyword-in-cpp/
    {
        int x = 9;
        const int z = 10;
        std::cout << "\t" << const_return_and_parameter(x) << '\n'
            << "\t" << const_return_and_parameter(z) << std::endl;
        //! The parameter admits "int" and "cont int" but don't allow the change of the value
        //! inside the fuction
    }
}
int main(){

    test_passing_argument_and_returning_values();
    test_calling_function_by_pointer();
    test_returning_values_functions();
    test_const_references();
 
    test_const_return();
    test_const_return_and_parameter();

    return 0;
}