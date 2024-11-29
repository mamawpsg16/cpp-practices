#ifndef TEST_H  // Include guard to prevent multiple inclusions
#define TEST_H

#include <iostream>

class Test {
public:
    Test() {
        std::cout << "SHEESH";
    }
};

#ifndef MATH_OPERATIONS_H  // Check if the macro is NOT defined
#define MATH_OPERATIONS_H  // Define the macro to indicate the file has been processed

// Declarations (available after the macro is defined)
int add(int a, int b);
int subtract(int a, int b);

#endif  // End of the #ifndef block (Prevents further inclusion)

#endif  // End of TEST_H