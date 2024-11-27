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
    string* ptr;
  public:
    CopyConstructor (const string& str) : ptr(new string(str)) {}
    // copy constructor:
    CopyConstructor (const CopyConstructor& x) : ptr(new string(x.content())) {}
    // access content:
    const string& content() const {return *ptr;}
    ~CopyConstructor () {delete ptr;}
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
    CopyConstructor foo ("Example");
    CopyConstructor bar = foo;

    cout << "bar's content: " << bar.content() << '\n';
    return 0;
}