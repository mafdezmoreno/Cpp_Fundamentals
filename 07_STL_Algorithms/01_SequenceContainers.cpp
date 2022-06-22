#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>

/*  ////! Which Sequence Chose:
    * Fast random acces: Array, Vector, Deque
    * Insertion and deletion fast: Forward List, List
    * Append fast: Vector (insert slow)
    * Addition and deletion supported: Vector, Forward List, List
*/

int main(){

    //! Array
    std::cout << "\nArray " << std::endl;
    int arr1[10]; // array declaration by specifying size
    int n = 10;
    int arr2[n];

    // Declaration by specifying size and initializing elements
    int arr3[6] = {10, 20, 30, 40};
    std::cout << "\t" << arr3[3] << std::endl;
    
    //! Vector
    std::cout << "\nVector " << std::endl;
    std::vector<int> my_vector;
    my_vector.push_back(100);
    // Both front and back of vector contains a value 100
    my_vector.push_back(10);
    // Now, the back of the vector holds 10 as a value, the front holds 100
    my_vector.front() -= my_vector.back();
    // We subtracted front value with back

    std::cout << "  Front of the vector: " << my_vector.front() << std::endl;
    std::cout << "  Back of the vector: " << my_vector.back() << std::endl;

    //! Deque
    //https://www.geeksforgeeks.org/deque-cpp-stl/
    std::cout << "\nDeque " << std::endl;
    std::deque<int> g_quiz;
    g_quiz.push_back(10);
    g_quiz.push_front(20);

    std::deque<int>::iterator it_1;
    std::cout << "\t";
    for (it_1 = g_quiz.begin(); it_1 != g_quiz.end(); ++it_1)
        std::cout << *it_1 << " ";
    std::cout << std::endl;

    //! Forward-list
    std::cout << "\nForward-list " << std::endl;
    std::forward_list<int> f_list1;
    f_list1.assign({ 1, 2, 3 });
    f_list1.push_front(4);
    std::cout << "\t";
    for (int& a : f_list1)
        std::cout << a << " ";
    std::cout << std::endl;

    //! List
    std::cout << "\nList " << std::endl;
    std::list<int> l;
    l.push_back(2);
    l.push_front(5);

    std::list<int>::iterator it_2;
    std::cout << "\t";
    for (it_2 = l.begin(); it_2 != l.end(); ++it_2)
       std::cout << *it_2 << " ";
    std::cout << std::endl;
    return 0;
}