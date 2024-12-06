#include <iostream>
constexpr int foo() { return 42; }

int main() {
    int a = foo();    // `a` is initialized to 42 (runtime-modifiable)
    std::cout << a << "v1 \n";
    a = 10;           // `a` is modified here
    std::cout << a << "v2 \n";

    constexpr int size = 10; // Compile-time constant
    // size = 20; // Error: `size` cannot be modified because it's implicitly `const`

    int arr[size]; // Valid because `size` is a compile-time constant
    return 0;
}
