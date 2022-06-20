#include <iostream>
int main()
{
    //! References
    std::cout<< "\nREFERENCES" <<std::endl;
    int first_variable = 10;
    int &ref_name = first_variable; //! Creates an ALIAS

    std::cout << "Value of first_variable: " << first_variable << std::endl;
    std::cout << "Value of ref_name: " << ref_name << std::endl;
    //Output
    //Value of first_variable: 10
    //Value of ref_name: 10

    //!Pointers
    std::cout<< "\nPOINTERS" <<std::endl;
    int variable_name = 2;
    int * pointer_1 = &variable_name; //!Creates pointer to variable_name
    int * pointer_2 = pointer_1;  //!Creates copy of prev pointer 
    std::cout<< "Value: " << variable_name<< " | " 
            <<"pointer_1: " << pointer_1 << " | " 
            <<"pointer_2: " << pointer_2 << " | "
            <<"\nget_value_using_pointer (*pointer_2): " << *pointer_2
            << std::endl;
    int **point_to_pointer = &pointer_2;

    std::cout<< "point_to_pointer: " << point_to_pointer
        << "\npointer pointing: " << *point_to_pointer
        << "\nvalue pointing: " << **point_to_pointer
        <<std::endl;

    //! The const Qualifier
    std::cout<< "\nThe const Qualifier" << std::endl;
    const int imm = 10;
    std::cout << "const int imm = " << imm << std::endl;
    //Output: 10
    
    int imm_change = 11;
    std::cout << "imm = imm_change" << std::endl;
    //imm = imm_change; //! Error: We cannot change the value of imm
    std::cout<< "Error: We cannot change the value of imm" <<std::endl;
    std::cout << imm << std::endl;

    //! Try Cath
    std::cout<< "\nTry Cath" << std::endl;
    int x = 10; 
    try { 
        std::cout << "Inside try block" << std::endl;
        if (x > 0) // True
        { 
            std::cout << "Before \"throw\" statement"<< std::endl;
            throw x;// Following statement will be skipped
            std::cout << "After throw keyword" << std::endl; //! This line is not executed
        }
    } 
    catch (int x ) { 
        std::cout << "Inside catch block: Exception found" << std::endl;
    } 
    std::cout << "Outside try-catch block" << std::endl; 

/*
Output:
Inside try block
Inside catch block: Exception found
Outside try-catch block
*/
}
