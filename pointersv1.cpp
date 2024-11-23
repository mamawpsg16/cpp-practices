#include <iostream>
using namespace std;
int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
//   g = (*functocall)(x, y); // Explicit dereference
  g = functocall(x, y);    // Implicit dereference (simpler and preferred)
  return (g);
}

int main() {
    /** VOID POINTERS */
    // int num = 10;
    // float f = 3.14;
    // void* ptr; // Declaring a void pointer

    // ptr = &num; // Storing the address of an integer
    // cout << "Integer value: " << *(static_cast<int*>(ptr)) << endl;

    // ptr = &f; // Storing the address of a float
    // cout << "Float value: " << *(static_cast<float*>(ptr)) << endl;

    /** NULL POINTERS*/
    // int* ptr = nullptr; // Pointer is initialized to "null"
    // int * p = 0;
    // int * r = NULL; // Defined as an alias of some null pointer constant value (such as 0 or nullptr).


    // if (ptr == nullptr) { // Check if the pointer is null
    //     cout << "Pointer is null and not pointing to anything." << endl;
    // }

    /** INVALID POINTERS*/
    // int* ptr; // Pointer is declared but not initialized
    // cout << *ptr; // Uncommenting this will cause undefined behavior

    /** DANGLING POINTER */
    //   int* ptr = new int(42); // Dynamically allocate memory
    // delete ptr;             // Free the memory
    // Now, `ptr` is dangling because it still "points" to the freed memory

    // Using the pointer after deleting is dangerous:
    // *ptr = 10; // Uncommenting this causes undefined behavior

    // ptr = nullptr; // Fix: Reset pointer to null after deleting

    /** POINTERS TO FUNCTION */
    int m,n;
    int (*minus)(int,int) = subtraction;

    m = operation (7, 5, addition);
    n = operation (20, m, minus);
    cout <<n;
    return 0;
}
