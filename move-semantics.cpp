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

     // Overload operator<< to print the value of T directly
    friend std::ostream& operator<<(std::ostream& os, const T& t) {
        os << " T value: " << t.value;
        return os;
    }

    // For logging the value directly
    void logValue() const {
        std::cout << " T value: " << value << "\n";
    }
};

struct S {
    T* _t;

    // Constructor
    S(T t) : _t(new T(t)) {
        std::cout << "S Constructor\n";
    }

    // Copy Constructor
    S(const S& s) : _t(new T(*s._t)) {
        std::cout << "S Copy Constructor\n";
        _t->logValue(); // Log the value of T
    }

    // Copy Assignment Operator
    S& operator=(const S& s) {
        std::cout << "S Copy Assignment Operator\n";
        if (this == &s) return *this; // Handle self-assignment
        delete _t;
        _t = new T(*s._t);
        _t->logValue(); // Log the value of T
        return *this;
    }

    // Move Constructor
    S(S&& s) noexcept : _t(s._t) {
        std::cout << "S Move Constructor\n";
        _t->logValue(); // Log the value of T
        s._t = nullptr; // Nullify the source pointer
    }

    // Move Assignment Operator
    S& operator=(S&& s) noexcept {
        std::cout << "S Move Assignment Operator\n";
        if (this == &s) return *this; // Handle self-assignment
        delete _t;
        _t = s._t; // Steal the resource
        _t->logValue(); // Log the value of T
        s._t = nullptr; // Nullify the source pointer
        return *this;
    }

    // Destructor
    ~S() {
        std::cout << "S Destructor\n";
        if (_t) _t->logValue(); // Log the value before destruction
        delete _t;
    }
};

int main() {
    T t1(42);
    std::cout << "\n--- Creating s1 ---\n";
    S s1(t1);         // Calls constructor
    std::cout << "S1 VALUE" << *s1._t << '\n';

    std::cout << "\n--- Creating s2 (copying s1) ---\n";
    S s2(s1);         // Calls copy constructor

    std::cout << "\n--- Assigning s1 to s2 (copy assignment) ---\n";
    s2 = s1;          // Calls copy assignment operator

    std::cout << "\n--- Creating s3 (move from a temporary) ---\n";
    S s3(T(10));      // Calls move constructor indirectly via a temporary
    std::cout << "S3 VALUE" << *s3._t << "\n";
    std::cout << "\n--- Moving s2 into s3 (move assignment) ---\n";
    s3 = std::move(s2); // Calls move assignment operator
    // std::cout << "S3 VALUE V2" << *s2._t << "\n"; // ERROR S2 IS NOW NULL PTR
    std::cout << "\n--- Creating s5 (move from s1) ---\n";
    S s5 = std::move(s1); // Calls move constructor
    std::cout << "S5 VALUE" << *s5._t << '\n';

    return 0;
}
