//! Container Adaptors:

/*
 * Stack: LIFO
    * push(), top(), and pop() 
 * Queue: FIFO
    * push(), front(), back(), and pop()
 * Priority Queue: Elements have priority associated
    * push(), top(), and pop()  
 */ 

#include <iostream>
#include <stack>

struct RegistrationForm {
    std::string userName;
};

void processRegistration(RegistrationForm form) {
    std::cout << "Processing form for user: " << form.userName << std::endl;
}

void storeRegistrationForm(std::stack<RegistrationForm>& stack, RegistrationForm form) {

    stack.push(form);
    std::cout << "Pushed form for user " << form.userName << std::endl;

}
void endOfDayRegistrationProcessing(std::stack<RegistrationForm>& stack) {
    while(not stack.empty()) {
        processRegistration(stack.top());
        stack.pop(); //To remove the processed element
    }
}

int main(){

    std::stack<RegistrationForm> registrationForms;
    storeRegistrationForm(registrationForms, RegistrationForm{"Alice"});
    storeRegistrationForm(registrationForms, RegistrationForm{"Bob"});
    storeRegistrationForm(registrationForms, RegistrationForm{"Charlie"});
    endOfDayRegistrationProcessing(registrationForms);

}

