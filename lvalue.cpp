// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}
// LVALUE
int lv1{ 42 }; // Object 
int& lv2{ lv1 }; // Reveference to Object 
int* lv3{ &lv1 }; // Pointer to Object 
int lv5;
int& lv6 = lv5;

      
int& lv4() 
{ 
    // Function returning Lvalue Reference 
    return lv1; 
} 
    
int main() {
    int a = 10;
 
    // Declaring lvalue reference
    // (i.e variable a)
    int& lref = a;
 
    // Declaring rvalue reference
    int&& rref = 20;
 
    // Print the values
    cout << "lref = " << lref << endl;
    cout << "rref = " << rref << endl;
 
    // Value of both a
    // and lref is changed
    lref = 30;
 
    // Value of rref is changed
    rref = 40;
    cout << "lref = " << lref << endl;
    cout << "rref = " << rref << endl;
 
    // This line will generate an error
    // as l-value cannot be assigned
    // to the r-value references
    // int &&ref = a;
    
    // Creating the references of the// parameter passed to the function
    // Given values
    int a1{ 10 }, b1{ 20 };
    cout << "a1 = " << a1 << " b1 = " << b1 << endl;
 
    // Call by Reference
    swap(a1, b1);
 
    // Print the value
    cout << "a1 v2 = " << a1 << " b1 v2 = " << b1 << endl;
    
 
    cout << lv1 << "\tObject" << endl; 
    cout << lv2 << "\tReference" << endl; 
    cout << lv3 << "\tPointer (object)" << endl; 
    cout << *lv3 << "\tPointer (value=locator)" << endl; 
    cout << lv4() << "\tFunction provided reference" << endl; 
    cout << lv5 << "\tObject" << endl; 
    cout << lv6 << "\tReference" << endl; 
  
    // Use the lvalue as the target 
    // of an assignment expression 
    lv1 = 10; 
    cout << lv4() << "\tAssignment to object locator" << endl; 
    lv2 = 20; 
    cout << lv4() << "\tAssignment to reference locator" << endl; 
    *lv3 = 30; 
    cout << lv4() << "\tAssignment to pointer locator" << endl; 
  
    // Use the lvalue on the right hand side 
    // of an assignment expression 
    // Note that according to the specification, 
    // those lvalues will first 
    // be converted to prvalues! But 
    // in the expression below, they are 
    // still lvalues... 
     cout << lv1 << '\t' <<  lv2 << '\t'  << *lv3 << '\t' << "OUTPUT lv1 - 3" << endl; 
    lv4() = lv1 + lv2 + *lv3; 
    cout << lv1 << "\tAssignment to reference locator (from function)\n"
                   "\t\tresult obtained from lvalues to the right of\n"
                   "\t\tassignment operator"
         << endl; 
      

    return 0;
}