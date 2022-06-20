
//!Private: Members declared as private can only be accessed by the functions inside 
//!the class and are not allowed to be accessed directly outside the class

//!Protected: Members declared as protected can only be accessed by the functions inside 
//!the class and the derived classes.

//!Public: Members declared as public can be accessed from anywhere in the program

class ClassName {
  private:
    int privateDataMember;
    int privateMemberFunction();

  protected:
    float protectedDataMember;
    float protectedMemberFunction();

  public:
    double publicDataMember;
    double publicMemberFunction();
};

//!Example of instances:

ClassName c1;
ClassName c2;