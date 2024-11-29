#include <iostream>
#include "test.h"  // Include the header file to use the declarations

using namespace std;
// (#define, #undef)
#define PI 3.14159 // Define a constant for the value of π

#define BEGIN_GENERATED_CODE \
    std::cout << "This is starting code!" << std::endl;
#define END_GENERATED_CODE \
    std::cout << "This is ending code!" << std::endl;
// Macro definition with parameters (acts like an inline function)
#define SQUARE(x) ((x) * (x)) // Define a macro to calculate the square of a number

// Conditional compilation using macros
// #define DEBUG // Define DEBUG to enable debugging features

#define STRINGIFY(x) #x // Stringizes the argument
#define CONCAT(a, b) a##b // Concatenates the arguments
#define CREATE_VARIABLE(name, value) int name##value = value

/** CONDITIONAL INCLUSIONS  (#ifdef, #ifndef, #if, #endif, #else and #elif) */
#define DEBUG 1  // Define DEBUG as 1
#define VERSION 2

/** LINE CONTROL */
// #line 1000 "preproc
// Function definitions (Implementation)

/** INCLUDE */

int main(){
  // Using the PI macro
    // std::cout << "The value of PI is: " << PI << std::endl;

    // Using the SQUARE macro
    // int num = 5;
    // std::cout << "The square of " << num << " is: " << SQUARE(num) << std::endl;

        // Conditional debugging code
    // #ifdef DEBUG
    //     std::cout << "Debug mode is enabled!" << std::endl;
    // #endif

    // Undefine the DEBUG macro
    // #undef DEBUG

        // Code after undefining DEBUG
    // #ifdef DEBUG
        // std::cout << "This will not be printed because DEBUG is undefined." << std::endl;
    // #else
        // std::cout << "Debug mode is now disabled!" << std::endl;
    // #endif

    // cout << STRINGIFY(Hello World) << std::endl; // Output: "Hello World"
    // int var1 = 42; // Declare a variable named "var1"
    // std::cout << CONCAT(var, 1) << std::endl; // Expands to "var1", Output: 42
    // CREATE_VARIABLE(myVar, 123); // Expands to: int myVar123 = 123
    // std::cout << myVar123 << std::endl; // Output: 123

    /** CONDITIONAL INCLUSIONS  (#ifdef, #ifndef, #if, #endif, #else and #elif) */
    // Conditional compilation using #if
    // #if DEBUG == 1
    //     std::cout << "Debug mode is enabled" << std::endl;
    // #else
    //     std::cout << "Debug mode is disabled" << std::endl;
    // #endif

    // // Nested conditional compilation
    // #if VERSION == 1
    //     std::cout << "Version 1 is selected" << std::endl;
    // #elif VERSION == 2
    //     std::cout << "Version 2 is selected" << std::endl;
    // #else
    //     std::cout << "Unknown version" << std::endl;
    // #endif

    /** LINE CONTROL #line*/
    // #line 100 "generated_code.cpp" // Indicate line 100 in generated_code.cpp
    // BEGIN_GENERATED_CODE
    // #line 200 "generated_code.cpp" // Indicate line 200 in generated_code.cpp
    // int a?;  //ERROR  generated_code.cpp:201:10: INSTEAD OF # 77
    // END_GENERATED_CODE

    /** ERROR DIRECTIVE  (#error) */ 
    // #ifdef __cplusplus
    //     #error A C++ compiler is required!
    // #endif 
    
    /** SOURCE FILE INCLUSION #include*/
    // Test test;
    // // Function definitions (Implementation)
    // int result = add(5, 3);  // Call add() function
    // std::cout << "Addition result: " << result << std::endl;

    // result = subtract(10, 4);  // Call subtract() function
    // std::cout << "Subtraction result: " << result << std::endl;

    /** PRAGMA DIRECTIVE */
    // #pragma once  // Ensures this header is included only once

    /** PREDEFINED MACRO NAMES */
    cout << "Compiled on: " << __DATE__ << endl;
    cout << "This is the line number " << __LINE__;
    cout << " of file " << __FILE__ << ".\n";
    cout << "Its compilation began " << __DATE__;
    cout << " at " << __TIME__ << ".\n";
    cout << "The compiler gives a __cplusplus value of " << __cplusplus;
    return 0;
}