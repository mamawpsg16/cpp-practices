#include <iostream>
#include <vector>
#include <algorithm>

// USAGE [capture](parameters) -> return_type { body }


int main() {
    //EXAMPLE #1
    // Simple lambda that adds two numbers
    // auto add = [](int a, int b) {
    //     return a + b;
    // };

    // std::cout << "Sum: " << add(3, 4) << std::endl;  // Output: Sum: 7


    //EXAMPLE #2
    // Lambda captures x by value, y by reference
    // int x = 5;
    // int y = 10;
    // auto printSum = [x, &y]() {
    //     std::cout << "Sum: " << x + y << std::endl; // x is captured by value, y by reference
    //     y = 20;  // Modify y (since it was captured by reference)
    // };

    // printSum();  // Output: Sum: 15
    // std::cout << "y after modification: " << y << std::endl;  // Output: y after modification: 20


    //EXAMPLE #3
    // A lambda with no parameters that prints a message
    // auto printMessage = []() {
    //     std::cout << "Hello, Lambda!" << std::endl;
    // };
    // printMessage();

    //EXAMPLE #4
    // Lambda with return type specified
    // auto multiply = [](int a, int b) -> int {
    //     return a * b;
    // };

    // std::cout << "Multiplication: " << multiply(3, 4) << std::endl;  // Output: Multiplication: 12

    //EXAMPLE #5
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Using lambda with std::for_each
    std::for_each(vec.begin(), vec.end(), [](int n) {
        std::cout << n * n << " ";  // Print square of each number
    });
    return 0;
}
