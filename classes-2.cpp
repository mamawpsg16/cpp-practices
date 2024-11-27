#include <iostream>
using namespace std;
class CVector {
    public:
        int x, y;  // The two components of the vector: x and y.

        // Default constructor: It does nothing in this case, but you can create an empty vector.
        CVector() {}

        // Parameterized constructor: Initializes a vector with specific x and y values.
        CVector(int a, int b) : x(a), y(b) {}

        // Overloading the '+' operator: This function defines how two vectors are added.
        // CVector operator+(const CVector& param); // Declaration of the operator+ function.
};

// Define the '+' operator for the CVector class.
// CVector is the return type.
// CVector::operator+ means that the operator+ is a member function of the CVector class.
// const CVector& param is the parameter passed into the function (the second vector that will be added to the current object).
// CVector CVector::operator+(const CVector& param) {
//     CVector temp; // Create a temporary CVector object to hold the result of the addition.
    
//     // Add the x components of the current object and the passed object (param).
//     temp.x = x + param.x;

//     // Add the y components of the current object and the passed object (param).
//     temp.y = y + param.y;

//     // Return the resulting vector (temp).
//     return temp;
// }

// Non-member function to overload the '+' operator for the CVector class.
CVector operator+ (const CVector& lhs, const CVector& rhs) {
  // Create a temporary CVector object to hold the result of the addition.
  CVector temp;

  // Add the x components of the two vectors (lhs and rhs) and store the result in temp.x.
  temp.x = lhs.x + rhs.x;

  // Add the y components of the two vectors (lhs and rhs) and store the result in temp.y.
  temp.y = lhs.y + rhs.y;

  // Return the resulting CVector object, which holds the sum of the two input vectors.
  return temp;
}

class Dummy {
  public:
    bool isitme(Dummy& param);  // Function declaration: takes a reference to a Dummy object
};

bool Dummy::isitme (Dummy& param)
{
    // `this` is a pointer to the current object (the one on which the method was called)
    // `param` is a reference to another Dummy object passed as an argument
    // Checking if the address of `param` is the same as the current object (`this`)
    if (&param == this) return true;  // If the address of `param` is the same as the current object, return true
    else return false;                // Otherwise, return false
}

class DummyV1 {
  public:
    // Static member variable declaration
    static int n;

    // Constructor increments the static member n every time an object is created
    DummyV1 () { 
        n++; // Increment the static member n whenever a Dummy object is created
    }
};

// Definition and initialization of the static member outside the class
int DummyV1::n = 0;


class MyClass {
  public:
    int x;
    MyClass(int val) : x(val) {}
    
    // Non-const member function: This can modify the object's state ( non-const member functions cannot be called on const objects )
    // int get() { 
    //     return x; 
    // }

    // Const member function: This guarantees not to modify the object's state
    //This is a const member function that returns a copy of the member variable x.
    // Since it returns a copy of x, the caller gets a new independent value, and modifying the returned value does not affect the original member x.
    //int get() const {return x;}        // const member function
    // const int& get() {return x;}       // member function returning a const&
    // const int& get() const {return x;} // const member function returning a const& 

    // int get() const {
    //     return x;
    // }
};

class MyClassV1 {
    int x;
  public:
    MyClassV1(int val) : x(val) {}
    // Const-qualified member function returning a const reference to x
    const int& get() const {
        return x; // Return a reference to x (read-only access)
    }
};

void print (const MyClassV1& arg) {
// Call the const member function `get()` on the passed object `arg`
// and print the value it returns
  cout << arg.get() << '\n';
}


class MyClassV2 {
    int x;
  public:
    MyClassV2(int val) : x(val) {}
     // Const-qualified function for const objects
    const int& get() const { 
        return x; // Returns a const reference to x (read-only access)
    }

    // Non-const function for non-const objects
    int& get() { 
        return x; // Returns a non-const reference to x (read-write access)
    }
};

/** CLASS TEMPLATES */
// Declare a template with a type parameter `T`
template <class T>
class mypair {
    // Declare two private members of type T
    T a, b;

  public:
    // Constructor: initializes `a` and `b` with values of type T
    mypair (T first, T second)
    {
        a = first; // Assign `first` to `a`
        b = second; // Assign `second` to `b`
    }

    // Member function to return the maximum of `a` and `b`
    T getmax ();
};

// Define the `getmax` function outside the class
template <class T>
T mypair<T>::getmax ()
{
    T retval;
    // Use a ternary operator to find the maximum of `a` and `b`
    retval = a > b ? a : b;
    return retval; // Return the maximum value
}

/** TEMPLATE SPECIALIZATION */

// Generic class template definition for mycontainer
template <class T>
class mycontainer {
    T element; // The container holds an element of type T
  public:
    // Constructor that initializes the element with the provided argument
    mycontainer (T arg) { element = arg; }

    // Member function to increase the value of the element (works for numerical types)
    T increase () { return ++element; }
};

// Specialization of the class template for the 'char' type
template <>
class mycontainer <char> {
    char element; // The container holds a char element
  public:
    // Constructor to initialize the char element
    mycontainer (char arg) { element = arg; }

    // Member function to convert a lowercase character to uppercase
    char uppercase ()
    {
      // Check if the element is a lowercase letter
      if ((element >= 'a') && (element <= 'z'))
        // Convert the lowercase letter to uppercase by adjusting its ASCII value
        element += 'A' - 'a';
      
      return element; // Return the modified or unchanged character
    }
};

int main(){
    
    /** OVERLOADING OPERATORS */
        // OVERLOADABLE OPERATORS
        // +    -    *    /    =    

        // >    +=   -=   *=   /=    >>

        // =  >>=  ==   !=   
        
        // =   >=   ++   --   %    &    ^    !    |

        // ~    &=   ^=   |=   &&   ||   %=   []   ()   ,    ->*  ->   new 

        // delete    new[]     delete[]

        //EXAMPLE #1
 
    //EXAMPLE #1
    // Create a vector 'foo' with x = 3, y = 1.
    // CVector foo(3, 1);
    
    // Create a vector 'bar' with x = 1, y = 2.
    // CVector bar(1, 2);
    
    // Create an empty vector 'result' to hold the sum of foo and bar.
    // CVector result;
    
    // Add foo and bar using the overloaded '+' operator. This calls the operator+ function.

    // foo is the current object (the object on the left side of the + operator). In the function, this refers to foo.
    // bar is passed as the parameter to the function, which means that param refers to bar.
    //WAYS TO USE IT :    
    // result = foo + bar;
    // result = foo.operator+  (bar);

    // Output the result: (x = 4, y = 3).
    // cout << result.x << ',' << result.y << '\n'; // Prints: 4,3

    //EXAMPLE #2
    // CVector foo (3,1);
    // CVector bar (1,2);
    // CVector result;
    // result = foo + bar;
    // cout << result.x << ',' << result.y << '\n';

    /** THE KEYWORD THIS */
    // Dummy a;             // Create an object `a` of type `Dummy`
    // Dummy* b = &a;       // Pointer `b` now points to `a`
    
    // // Call the `isitme` method on the object pointed to by `b`, passing `a` as the argument
    // if (b->isitme(a))    // `b->isitme(a)` will check if `a` and the current object (which is `b` -> `a`) are the same
    //     cout << "yes, &a is b\n";   // Since `b` points to `a`, this will print "yes, &a is b"

    /** STATIC MEMBERS */
    // Creating an object 'a' of type Dummy
    // DummyV1 a;  // This will call the constructor, and n will be incremented to 1

    // // Creating an array of Dummy objects 'b' with 5 elements
    // DummyV1 b[5];  // This will create 5 objects, and each will call the constructor,
    //              // so n will be incremented by 5, making it 6

    // // Printing the value of static member 'n' using the object 'a'
    // cout << a.n << '\n';  // It prints 6 because static members are shared across all instances

    // // Creating a dynamic object 'c' using new
    // DummyV1 * c = new DummyV1;  // This will create one more DummyV1 object, incrementing n to 7

    // // Printing the value of static member 'n' using the class name
    // cout << DummyV1::n << '\n';  // It prints 7 because static members are accessed using the class name too

    // // Deleting the dynamic object 'c' (though it does not affect 'n')
    // delete c;

    /** CONST MEMBER FUNCTIONS */
    //EXAMPLE #1
    // const MyClass foo(10);  // Create a const object
    // // foo.x = 20;            // not valid: x cannot be modified
    // // cout << foo.get() << '\n';  // ERROR: Cannot call non-const function on a const object // A copy of `x` is returned
    // cout << foo.x << '\n';  // ok: data member x can be read
    
    //EXAMPLE #2
    // MyClassV1 foo(10);   // Create a MyClassV1 object with x initialized to 10
    // print(foo);          // Call the `print` function, passing foo by const reference

    //EXAMPLE #3
    // MyClassV2 foo(10);         // Non-const object
    // const MyClassV2 bar(20);   // Const object

    // foo.get() = 15;          // OK: Non-const get() returns int& (modifiable reference)
    // // bar.get() = 25;       // ERROR: Const get() returns const int& (read-only)

    // cout << foo.get() << '\n'; // Outputs 15 (modified value)
    // cout << bar.get() << '\n'; // Outputs 20 (original value)

    /** CLASS TEMPLATES */
    //  Create an instance of the `mypair` class with `int` as the type
    // mypair <int> myobject (100, 75); // `a` is 100, `b` is 75

    // // Call the `getmax` function and print the result
    // cout << myobject.getmax(); // Output will be: 100

    /** TEMPLATE SPECIALIZATION */
    // Create an instance of the mycontainer template with int type (generic version)
    mycontainer<int> myint(7); // Initializes the container with an integer element (7)

    // Create an instance of the mycontainer template with char type (specialized version)
    mycontainer<char> mychar('j'); // Initializes the container with a char element ('j')

    // Call the increase function on the integer container, which increments the value
    cout << myint.increase() << endl; // Outputs: 8

    // Call the uppercase function on the char container, which converts 'j' to uppercase
    cout << mychar.uppercase() << endl; // Outputs: J
    return 0;
}