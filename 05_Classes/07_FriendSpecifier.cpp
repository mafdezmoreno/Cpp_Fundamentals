#include <iostream>

/* //!Friend Specifier
A class can declare another function or class as a friend: this function or class 
will have access to the private and protected members of the class which declares 
the friend relationship
*/

class friend_class_1; //! Forward declaration
class friend_class_2; //! Forward declaration

class class_name {

    public:
        class_name(const std::string & name);

        friend void print(const class_name &obj); //! Friend function
        friend class friend_class_1; //! Friend class
        friend class friend_class_2; //! Friend class

        void get_info_friend_class(friend_class_1 &f1);

        /* //!!Error Friendship is NOT MUTUAL
        void get_info_friend_class(friend_class_2 &f2){
            std::cout << "id of friend class: " << f2.id << std::endl; 
        }
        */
        ~class_name();

    private:
        int _member_1;
        int _member_2;
        std::string _name;
};

class friend_class_1 {
    
    public:
        friend_class_1(const std::string & name);
        ~friend_class_1();

    private:
        int id = 1;
        friend class class_name;
        std::string _name;
};

class friend_class_2 {
    
    public:
        friend_class_2(const std::string & name);
        void print_info_class_name (class_name &c1);
        ~friend_class_2();

    private:
        int id = 2;
        std::string _name;
};

class_name::class_name(const std::string &name): _member_1(0), _member_2(0){
    std::cout << "Constructor " << this << " for " << name <<" called" <<std::endl;
    _name = name;
};
class_name::~class_name(){
    std::cout << "Destructor " << this << " for " << _name <<" called" <<std::endl;
};

friend_class_1::friend_class_1(const std::string & name){
    _name = name;
    std::cout << "Constructor " << this << " for " << name <<" called" <<std::endl;
}
friend_class_1::~friend_class_1(){
    std::cout << "Destructor " << this << " for " << _name <<" called" <<std::endl;
}

friend_class_2::friend_class_2(const std::string &name){
    _name = name;
    std::cout << "Constructor " << this << " for " << name <<" called" <<std::endl;
}

friend_class_2::~friend_class_2(){
    std::cout << "Destructor " << this << " for " << _name <<" called" <<std::endl;
}

void class_name::get_info_friend_class(friend_class_1 &f1){
    std::cout << _name <<" can acces his friend " << f1._name << std::endl; 
}

void friend_class_2::print_info_class_name (class_name &c1){
    std::cout << _name << " can acces his friend " << c1._name << "\n"
        << "\tmember 1: " << c1._member_1<< "\n" 
        << "\tmember 2: "<< c1._member_2 <<std::endl;
}

//! Friend function (declared in class with specifier "friend")
void print(const class_name &obj){
    std::cout << "An friend external function can acces members of "
        << obj._name << std::endl;
    std::cout << "\tMember 1: " << obj._member_1 << "\n" 
              << "\tMember 2: " << obj._member_2 << std::endl;
}

/* //! Error unable to compile with this function declared
void non_friend_print(const class_name &obj){
    std::cout << obj._member_1 << " " << obj._member_2 << std::endl;
}*/

int main(){

    class_name c1(std::string("c1"));

    //! Friend function
    print(c1);
    //non_friend_print(c1); //!Error

    //! Friend class
    friend_class_1 f1(std::string("f1")); 
    c1.get_info_friend_class(f1); //

    friend_class_2 f2(std::string("f2"));
    f2.print_info_class_name(c1); 
    /* //!!Error Friendship is NOT MUTUAL
    c1.get_info_friend_class(f2);
    */

    return 0;
}