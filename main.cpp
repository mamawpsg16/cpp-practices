#include <iostream>
#include "test.h"

int main() {
    int result = add(5, 3);
    std::cout << "Addition result: " << result << std::endl;
    
    result = subtract(10, 4);
    std::cout << "Subtraction result: " << result << std::endl;
    
    return 0;
}