#include <iostream>
#include <utility> // For std::move

struct T {
    int value;
    T(int val) : value(val) {
        std::cout << "T Constructor (" << value << ")\n";
    }
    ~T() {
        std::cout << "T Destructor (" << value << ")\n";
    }
};

struct S {
    T* _t;

    // Constructor
    S(T t) : _t(new T(t)) {
        std::cout << "S Constructor\n";
    }

    // Move Constructor
    S(S&& s) noexcept : _t(s._t) {
        std::cout << "S Move Constructor\n";
        s._t = nullptr; // Nullify the source pointer
    }

    // Destructor
    ~S() {
        std::cout << "S Destructor\n";
        delete _t;
    }
};

int main() {
    T t1(42);
    S s1(t1); // Create object with resource

    std::cout << "\n--- Moving s1 into s2 ---\n";
    S s2 = std::move(s1); // Move s1 into s2

    // Attempting to access s1 after the move
    if (s1._t) {
        std::cout << "S1 VALUE: " << s1._t->value << "\n"; // Access value
    } else {
        std::cout << "S1 VALUE: nullptr (moved)\n";
    }

    return 0;
}
