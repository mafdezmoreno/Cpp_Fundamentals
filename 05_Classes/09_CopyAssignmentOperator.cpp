#include <iostream>
#include <string>
    
// References: 
// https://www.codementor.io/@sandesh87/the-rule-of-five-in-c-1pdgpzb04f
// geeksforgeeks has also a similar example:
// https://www.geeksforgeeks.org/copy-constructor-vs-assignment-operator-in-c/


class class_name {

    public:

        int* data;
        int id;

        class_name(){
            std::cout << "  Def. Constructor called: " << this << std::endl;
            id = 222;
            data = new int(333);
        }
        
        //!Copy constructor
        class_name(const class_name& other){
            std::cout << "  Copy constructor called from: "
                << this << " to copy " << &other << std::endl;
            //variable:
            this->id = other.id; //or simply: id = other.id
            //pointer:
            this->data = new int;
            *data = *other.data;
        }

        //!Copy assignment
        class_name& operator= (const class_name & other) {
            
            std::cout << "  Copy assig. op. called from:  "
                << this << " to copy " << &other << std::endl;

            if (this != &other){ //To prevent auto-assignment
                //variable
                id = other.id;
                //pointer
                //delete old data:
                if (data){
                    delete data;
                }
                data = new int;
                *data = *other.data;
            }

            return *this; //To avoid compiler warning
            //! geeksforgeeks implement "return *this" in his example
        }

        //!Due to RULE OF FIVE if it's needed the previous implementations has to be
        // implemented also the "move constructor" and "move assignment" and the
        // "destructor" (and vice versa). They are implemented in the next example.

        ~class_name(){
            std::cout << "Destructor called " << this << std::endl;
            if (data){
                delete data;
                std::cout << "\tData Deleted " <<std::endl;
            }
        }

    private:
        //Empty for testing reasons (variables should be here)
};

int main(){

    std::cout << "\nInstance creation: " <<std::endl;
    class_name obj;

    std::cout << "\nConstruction copying the prev instance: " <<std::endl;
    class_name other_obj1(obj);
    // prints "Copy constructor called!"

    std::cout << "\nAssigning new creation to previous object call also de copy constructor: " <<std::endl;
    class_name other_obj2 = obj; //! Error on book (It call Copy constructor)
    std::cout << "\nCopying the prev instance into another: " <<std::endl;
    class_name obj_1;
    obj_1 = obj;
    // prints "Copy assignment operator called!"

    std::cout << "\nChecking that copies have different memory positions:" << std::endl;
    std::cout << &obj << " data: " <<  *obj.data << " " << obj.data <<std::endl;
    std::cout << &other_obj1 << " data: " <<  *other_obj1.data <<  " " << other_obj1.data <<std::endl;
    std::cout << &other_obj2 << " data: " <<  *other_obj2.data<<  " " << other_obj2.data <<std::endl;
    std::cout << &obj_1 << " data: " <<  *obj_1.data <<  " " << obj_1.data << std::endl;

}