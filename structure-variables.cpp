// My second program in C++
#include <iostream>
using namespace std;
#include <string>


int main()
{
    // int num; // Variable to store the input
    // cout << "Enter a number: ";
    // cin >> num; // Take input from the user
    // cout << "You entered: " << num << endl;
    
     // declaring variables:
    int a, b;
    int result;

    // process:
    a = 5;
    b = 2;
    a = a + 1;
    cout << a <<endl;
    result = a - b;

    cout << result <<endl;

    int foo = 0;
    string bar = "Bar";
    decltype(foo) baz;  
    cout << bar <<endl;
    cout << "Type of foo: " << typeid(foo).name() << endl;
    cout << "Type of bar: " << typeid(bar).name() << endl;
    cout << "Type of baz: " << typeid(baz).name() << endl;

    unsigned int unsignedVar = 10;  // unsigned int type
    cout << "Unsigned variable value: " << unsignedVar << endl;

    unsignedVar = -5;  // No Error but -5 is interpreted as 4294967291 on a typical system with a 32-bit unsigned int (because 4294967296 - 5 = 4294967291).
    cout << "Updated unsigned variable value: " << unsignedVar << endl;
 

    return 0;
}
