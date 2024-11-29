#include <iostream>
#include <string>
using namespace std;
#include <stdexcept>
#include <exception>

/** DYNAMIC EXCEPTION SPECIFICATIONS */
// Function that declares it will only throw `int` or `std::runtime_error`
// void riskyFunction(int x) throw(int, std::runtime_error) {
//     if (x == 0)
//         throw std::runtime_error("Division by zero error!");
//     else if (x < 0)
//         throw x; // Throwing an integer exception
//     else
//         std::cout << "All good, x is: " << x << '\n';
// }

/** STANDARD EXCEPTIONS */
// Define a custom exception class that inherits from std::exception
class myexception : public exception {
public:
    // Override the what() method to provide a custom error message
    virtual const char* what() const throw() {
        return "My exception happened";  // Custom error message
    }
} myex;  // Create an instance of the custom exception

int main() {
    /** EXCEPTIONS */
    //   try {
    //     // throw "Kevin Mensah"; // Throws a const char*
    //     // throw string("Kevin Mensah v2");
    //     throw 10.9;
    //   }
    //   catch (int e) {
    //     cout << "An exception occurred. Exception Nr. " << e << '\n';
    //   }
    //   catch (char e) {
    //     cout << "char exception: " << e << '\n';
    //   }
    //   catch (const char* e) {
    //     cout << "const char* exception: " << e << '\n'; // This block will execute
    //   }
    //   catch (string e) {
    //     cout << "string exception: " << e << '\n';
    //   }catch (...) { 
    //     cout << "default exception";
    //     }

    /** EXCEPTION SPECIFICATION*/
    // try {
    //     riskyFunction(0); // Will throw std::runtime_error
    // } catch (const std::runtime_error& e) {
    //     std::cout << "Caught runtime_error: " << e.what() << '\n';
    // } catch (int e) {
    //     std::cout << "Caught int exception: " << e << '\n';
    // }

    // try {
    //     riskyFunction(-5); // Will throw an integer
    // } catch (const std::runtime_error& e) {
    //     std::cout << "Caught runtime_error: " << e.what() << '\n';
    // } catch (int e) {
    //     std::cout << "Caught int exception: " << e << '\n';
    // }

    /*** STANDARD EXCEPTIONS ***/

    // Example #1: Throwing and catching a custom exception
    // try {
    //     throw myex;  // Throw the custom exception
    // }
    // catch (exception& e) {  // Catch exceptions of type std::exception
    //     cout << e.what() << '\n';  // Print the custom error message
    // }

    // Example #2: Handling standard exceptions (e.g., memory allocation failure)
    //  try {
        // Attempt to allocate memory for a very large array.
        // If allocation fails, std::bad_alloc will be thrown.
    //     int* myarray = new int[100000000];  // Large allocation likely to fail
    // }
    // catch (exception& e) {  
        // Catch any exception derived from std::exception, including std::bad_alloc
        // cout << "Standard exception: " << e.what() << endl;  
        // e.what() will provide details about the exception (e.g., "bad_alloc")
    // }
  return 0;
}
