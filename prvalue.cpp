#include <iostream>
#include <string>

// §3.10.1 
// An rvalue is an xvalue, a temporary object (§12.2), 
// or a value not associated with an object 
// A prvalue is an rvalue that is NOT an xvalue 
  
// When a glvalue appears in a context 
// where a prvalue is expected, 
// the glvalue is converted to a prvalue 
int prv1{ 42 }; // Value 
  
constexpr int lv1{ 42 }; 
int prv2{ lv1 }; // Expression (lvalue) 
  
constexpr int f1(int x) 
{ 
    return 6 * x; 
} 
int prv3{ f1(7) }; // Expression (function return value) 
  
int prv4{ (lv1 + f1(7)) / 2 }; // Expression (temporary object) 

// Function that returns a prvalue
int foo() {
    return 42;  // The returned value is a prvalue
}

int main() {
    // Literal examples
    int intLiteral = 42;         // int literal is a prvalue
    double doubleLiteral = 3.14; // double literal is a prvalue
    char charLiteral = 'a';      // char literal is a prvalue
    bool boolLiteral = true;     // bool literal is a prvalue

    // Temporary object examples
    std::string tempString = std::string("hello"); // Temporary std::string object, prvalue
    int tempSum = 1 + 2;                           // The result of this expression is a prvalue

    // Type cast example
    int castValue = static_cast<int>(3.14);        // The result is a prvalue

    // Function return example
    int returnedValue = foo();                     // The return value of foo() is a prvalue

    // Output all values to verify
    std::cout << "intLiteral: " << intLiteral << '\n';
    std::cout << "doubleLiteral: " << doubleLiteral << '\n';
    std::cout << "charLiteral: " << charLiteral << '\n';
    std::cout << "boolLiteral: " << boolLiteral << '\n';
    std::cout << "tempString: " << tempString << '\n';
    std::cout << "tempSum: " << tempSum << '\n';
    std::cout << "castValue: " << castValue << '\n';
    std::cout << "returnedValue: " << returnedValue << '\n';

    // Print out the prvalues used 
    // in the initializations 
    std::cout << prv1 << " Value" << std::endl; 
    std::cout << prv2 << " Expression: lvalue" << std::endl; 
    std::cout << prv3 << " Expression: function return value" << std::endl; 
    std::cout << prv4 << " Expression: temporary object" << std::endl; 

    return 0;
}
