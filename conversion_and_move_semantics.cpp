#include <iostream>
#include <utility> // For std::move

class Resource {
public:
    int* data; // Pointer to dynamically allocated integer

    // Constructor
    Resource(int value) : data(new int(value)) {
        std::cout << "Resource acquired with value: " << *data << std::endl;
    }

    // Copy Constructor
    Resource(const Resource& other) : data(new int(*other.data)) {
        std::cout << "Resource copied with value: " << *data << std::endl;
    }

    // Move Constructor
    Resource(Resource&& other) noexcept : data(other.data) {
        other.data = nullptr; // Nullify the source pointer to prevent double deletion
        std::cout << "Resource moved with value: " << *data << std::endl;
    }

    // Copy Assignment Operator
    Resource& operator=(const Resource& other) {
        if (this != &other) { // Self-assignment check
            delete data; // Free existing resource
            data = new int(*other.data); // Copy the resource
            std::cout << "Resource copied via assignment with value: " << *data << std::endl;
        }
        return *this;
    }

    // Move Assignment Operator
    Resource& operator=(Resource&& other) noexcept {
        if (this != &other) { // Self-assignment check
            delete data; // Free existing resource
            data = other.data; // Steal the resource
            other.data = nullptr; // Nullify the source pointer
            std::cout << "Resource moved via assignment with value: " << *data << std::endl;
        }
        return *this;
    }

    // Destructor
    ~Resource() {
        if (data) {
            std::cout << "Resource destroyed with value: " << *data << std::endl;
            delete data; // Free allocated memory
        } else {
            std::cout << "Resource already null." << std::endl;
        }
    }
};

// Function to demonstrate implicit conversion and copy/move semantics
void demonstrateImplicitConversion() {
    Resource res1(10);           // Normal construction (value 10)
    
    Resource res2 = res1;       // Copy constructor called (res2 gets a copy of res1's value)
    
    Resource res3(20);
    res3 = res2;                // Copy assignment operator called (res3 gets a copy of res2's value)
    
    std::cout << "Value of res3 after copy assignment: " << *(res3.data) << std::endl;  // Should output 10

    Resource res4 = std::move(res1);  // Move constructor called (res4 takes ownership of res1's resource)
}

// Function to demonstrate assignment operators
void demonstrateAssignmentOperators() {
    Resource res5(30);           // Normal construction (value 30)
    
    Resource res6(40);
    res6 = std::move(res5);     // Move assignment operator called (res6 takes ownership of res5's resource)

    std::cout << "Value of res6 after move assignment: " << *(res6.data) << std::endl;  // Should output 30

    Resource res7(50);
    res7 = res6;                // Copy assignment operator called (res7 gets a copy of res6's value)

    std::cout << "Value of res7 after copy assignment: " << *(res7.data) << std::endl;  // Should output 30
}

int main() {
    demonstrateImplicitConversion();
    demonstrateAssignmentOperators();
    
    return 0;
}