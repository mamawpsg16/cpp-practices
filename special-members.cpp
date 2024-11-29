#include <iostream>
using namespace std;


class DefaultConstructor {
  string data;
  public:
    DefaultConstructor (const string& str) : data(str) {}
    DefaultConstructor() {}
    const string& content() const {return data;}
};

class DestructorClass {
    string* ptr;  // Pointer to a string, to dynamically allocate memory for the string data

public:
    // Default constructor:
    // This constructor initializes 'ptr' with a new string object (empty string).
    DestructorClass() : ptr(new string) {}

    // Parameterized constructor:
    // This constructor initializes 'ptr' with a new string object created from the given string argument.
    DestructorClass(const string& str) : ptr(new string(str)) {}

    // Destructor:
    // The destructor is called when the object goes out of scope or is deleted.
    // It deletes the dynamically allocated memory to prevent memory leaks.
    ~DestructorClass() {
        delete ptr;  // Deleting the memory allocated for the string object
    }

    // Accessor method:
    // This method returns a reference to the string content stored in the object.
    // The method is marked as 'const' because it does not modify the object's state.
    const string& content() const {
        return *ptr;  // Dereferencing 'ptr' to access the string data it points to
    }
};

class CopyConstructor {
    string* ptr; // Pointer to dynamically allocate a string

public:
    // Constructor: Dynamically allocates memory and initializes it with the given string
    CopyConstructor(const string& str) : ptr(new string(str)) {}

    // Copy Constructor:
    // This is called when a new object is initialized as a copy of an existing object
    CopyConstructor(const CopyConstructor& x) : ptr(new string(x.content())) {}

    // Accessor method to return the content of the string
    const string& content() const { return *ptr; }

    // Destructor: Releases the dynamically allocated memory
    ~CopyConstructor() { delete ptr; }
};

/** MOVE & ASSIGNMENT CONSTRUCTOR */

class Example6 {
    string* ptr; // Dynamically allocated string

public:
    // Constructor: Dynamically allocate memory for the string and initialize it
    Example6(const string& str) : ptr(new string(str)) {
        cout << "Constructor called for: " << *ptr << endl;
    }

    // Destructor: Free the dynamically allocated memory
    ~Example6() {
        if (ptr) {
            cout << "Destructor called for: " << *ptr << endl;
        } else {
            cout << "Destructor called for null resource" << endl;
        }
        delete ptr;
    }

    // Move Constructor: Transfers ownership of the resource from x to the current object
    Example6(Example6&& x) : ptr(x.ptr) {
        cout << "Move Constructor called" << endl;
        x.ptr = nullptr; // Nullify the source object's pointer to avoid double deletion
    }

    // Move Assignment Operator: Transfers ownership of the resource from x to the current object
    Example6& operator=(Example6&& x) {
        if (this == &x) return *this; // Handle self-assignment (e.g., obj = std::move(obj))

        cout << "Move Assignment Operator called" << endl;

        delete ptr;        // Free the current object's resource
        ptr = x.ptr;       // Transfer ownership of the resource
        x.ptr = nullptr;   // Nullify the source object's pointer
        return *this;      // Return the current object to allow for chaining
    }

    // Accessor Method: Get the content of the string
    const string& content() const { 
        return *ptr; 
    }

    // Addition Operator: Creates a new object with the concatenated content of two objects
    Example6 operator+(const Example6& rhs) {
        // Combine the content of the current object and rhs into a new temporary object
        return Example6(content() + rhs.content());
        // This temporary object will likely invoke the move constructor when returned
    }
};

/** IMPLICIT MEMBER */
class Rectangle {
    int width, height; // Private member variables
  public:
    // Parameterized constructor
    Rectangle(int x, int y) : width(x), height(y) {}
    
    // Default constructor: explicitly request the compiler to generate it
    Rectangle() = default; 

    // Delete the copy constructor: prevents copying of objects
    Rectangle(const Rectangle& other) = delete;

    // Member function to calculate the area of the rectangle
    int area() { return width * height; }
};
int main(){
    /** DEFAULT CONSTRUCTOR*/
    // DefaultConstructor foo;
    // DefaultConstructor bar ("Example");

    // cout << "bar's content: " << bar.content() << '\n';

    /** DESTRUCTOR */
   // Creating an object foo using the default constructor.
    // The ptr will point to a dynamically allocated empty string.
    // DestructorClass foo;

    // Creating an object bar using the parameterized constructor.
    // The ptr will point to a dynamically allocated string with the value "Example".
    // DestructorClass bar("Example");

    // Output the content of 'bar' using the content() method.
    // cout << "bar's content: " << bar.content() << '\n';  // Will print "Example"

    /** COPY CONSTRUCTOR */
    /** Creating an object using the parameterized constructor */
    // CopyConstructor foo("Example"); 
    // Dynamically allocates memory and stores "Example" in `foo`'s `ptr`.

    /** Copying the object foo into a new object bar using the copy constructor */
    // CopyConstructor bar = foo; 
    // Copy constructor is called here.
    // A new string is dynamically allocated for `bar`, and `foo`'s content ("Example") is copied into `bar`.

    /** Displaying the content of bar using the `content()` method */
    // cout << "bar's content: " << bar.content() << '\n'; 
    // Accesses `bar`'s content, which should output: "Example"

    /** MOVE CONSTRUCTOR AND ASSIGNMENT */
    //MyClass fn();            // function returning a MyClass object
    // MyClass foo;             // default constructor
    // MyClass bar = foo;       // copy constructor
    // MyClass baz = fn();      // move constructor
    // foo = bar;               // copy assignment
    // baz = MyClass();         // move assignment 

     // Create an object foo with the string "Exam"
    // Example6 foo("Exam");

    // Create a temporary object with the string "ple" and move it into bar
    // Example6 bar = Example6("ple"); // Move Constructor is called here
    // Example6 bar = std::move(Example6("ple"));


    // Concatenate foo and bar using the addition operator, which creates a temporary object.
    // Then, assign the result to foo using the move assignment operator.
    // foo = foo + bar; // Move Assignment Operator is called here

    // Print the content of foo, which now contains the concatenated string "Example"
    // cout << "foo's content: " << foo.content() << '\n';

    /** IMPLICIT MEMBERS */
    Rectangle foo;              // Calls the default constructor
    Rectangle bar(10, 20);      // Calls the parameterized constructor

    // Rectangle baz = bar;     // Uncommenting this would cause a compilation error due to deleted copy constructor

    cout << "bar's area: " << bar.area() << '\n'; // Calls the area function for bar

    return 0;
}