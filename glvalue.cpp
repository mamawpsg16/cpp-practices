#include <iostream>
#include <utility> // For std::move

// A simple function for demonstration
void func() {
    std::cout << "Function called.\n";
}

struct Point {
    int x, y;
};

int main() {
    // Example 1: lvalue (and hence a glvalue)
    int x = 10;
    int& ref = x;  // `x` and `ref` are lvalues, so they are glvalues
    std::cout << "x: " << x << ", ref: " << ref << '\n';

    // Example 2: xvalue (and hence a glvalue)
    int&& rvalueRef = std::move(x);  // `std::move(x)` is an xvalue
    std::cout << "rvalueRef (after move): " << rvalueRef << '\n';

    // Example 3: Function name as a glvalue
    func; // The name of the function `func` is a glvalue
    func(); // Calls the function

    // Example 4: Array subscript (produces an lvalue, hence a glvalue)
    int arr[3] = {1, 2, 3};
    std::cout << "arr[1]: " << arr[1] << '\n';

    // Example 5: Dereferencing a pointer (produces an lvalue, hence a glvalue)
    int* ptr = &x;
    *ptr = 20; // Dereferencing `ptr` refers to the same memory location as `x`
    std::cout << "After modifying via pointer, x: " << x << '\n';

    // Example 6: Member access (produces an lvalue, hence a glvalue)
    Point p{5, 10};
    std::cout << "p.x: " << p.x << ", p.y: " << p.y << '\n';

    return 0;
}
