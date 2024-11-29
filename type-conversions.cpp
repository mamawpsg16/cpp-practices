#include<iostream>
using namespace std;
#include <typeinfo>
#include <exception>
/** IMPLICIT CONVERSIONS WITH CLASSES */

// Class A is a simple, empty class
class A {};

// Class B demonstrates implicit conversions with constructors, assignment operators, and type-cast operators.
class B {
    public:
    // Constructor for converting an object of type A to type B
    // This is an implicit conversion from A to B
    B (const A& x) {
        // constructor body (not implemented here)
    }

    // Assignment operator for converting an object of type A to type B
    // This is another implicit conversion from A to B via assignment
    B& operator= (const A& x) {
        // assignment body (not implemented here)
        return *this; // return the current object for chained assignment
    }

    // Type-cast operator for converting an object of type B to type A
    // This allows an object of type B to be implicitly converted to type A
    operator A() {
        return A(); // create and return an object of type A
    }
};

/** KEYWORD EXPLICIT */
// Class A is a simple, empty class
class AV1 {};

// Class B demonstrates implicit conversions and the use of the 'explicit' keyword.
class BV1 {
public:
  // 'explicit' prevents implicit conversion from A to B
  // This constructor can only be called explicitly, not implicitly
  explicit BV1 (const AV1& x) {
    // constructor body (not implemented here)
  }

  // Assignment operator for converting an object of type A to type B
  BV1& operator= (const AV1& x) {
    // assignment body (not implemented here)
    return *this; // return the current object for chained assignment
  }

  // Type-cast operator for converting an object of type B to type A
  operator AV1() {
    return AV1(); // create and return an object of type A
  }
};

// Function that takes an object of type B by value
void fn (BV1 x) {}

/** TYPE CASTING */
class Dummy {
    double i,j;
};

class Addition {
    int x,y;
  public:
    Addition (int a, int b) : x(a), y(b) {}

    int result() { return x+y;}
};

/** DYNAMIC_CAST */
/** Base class with a virtual function */
class Base {
    virtual void dummy() {}  // The dummy function is here just to make Base a polymorphic class
};

/** Derived class inheriting from Base */
class Derived : public Base {
    int a;  // Data member specific to Derived class
};

/** STATIC_CAST */
class BaseV1 {};
class DerivedV1: public BaseV1 {};

/** CONST_CAST */

void print(char *str) {
    cout << str << '\n';  // Prints the string pointed to by `str`
}

/** */
class BaseV3 { 
    virtual void f(){}  // This makes the class polymorphic by defining a virtual function
};

class DerivedV3 : public BaseV3 {};  // Derived class that inherits from Base

int main(){
    // Implicit conversion with built-in types
    // short a = 2000; // a short variable
    // int b;          // an integer variable
    // b = a;          // implicit conversion from short to int (works because short can be safely promoted to int)
    /** IMPLICIT CONVERSIONS WITH CLASSES */

    // Demonstrating implicit conversions with classes
    // A foo;          // create an object of type A
    // B bar = foo;     // implicit conversion: calls constructor of B, converting A to B
    // bar = foo;       // implicit conversion: calls assignment operator of B, converting A to B
    // foo = bar;       // implicit conversion: calls type-cast operator of B, converting B to A

    /** KEYWORD EXPLICIT */
    // AV1 fooV1;      // create an object of type A
    // BV1 barV1(fooV1); // explicit conversion: this calls the constructor B(const A& x)
    
    // barV1 = fooV1;  // assignment: uses the assignment operator B& operator= (const A& x)
    
    // fooV1 = barV1;  // type-cast: uses the type-cast operator operator A()

    // fn(foo);  // NOT allowed because the constructor of B is explicit.
    // fn(barV1);    // Allowed because bar is of type B, and fn() takes an object of type B.

    /** TYPE CASTING */
    //EXAMPLE #1
    // double x = 10.3;
    // int y;
    // Output the current value of x
    // cout << "old value of x : " << x << endl; // Prints: old value of x : 10.3

    // First type cast (using functional notation) to convert x to an integer
    // The fractional part of 'x' (0.3) will be discarded, leaving only the integer part (10)
    // y = int(x);  // x is cast to an integer (10), and assigned to y
    // At this point, 'y' holds 10, but the value of 'x' is still 10.3

    // Output the value of x (which hasn't changed, since casting only affects the result)
    // cout << "new value of x : " << x << endl; // Prints: new value of x : 10.3
    // cout << "new value of y : " << y << endl; // Prints: new value of x : 10.3

    // Second type cast (using C-style cast) to convert x to an integer
    // Again, the fractional part of 'x' is discarded, and the result is assigned to 'y'
    // y = (int) x;  // x is cast to an integer (10), and assigned to y
    // At this point, 'y' holds 10, but the value of 'x' is still 10.3

    // Output the value of x again (it remains unchanged)
    // cout << "new value of x : " << x << endl; // Prints: new value of x v2 : 10.3
    // cout << "new value of y : " << y << endl; // Prints: new value of x v2 : 10.3

    //EXAMPLE #2
    // Dummy d;
    // Addition * padd;
    // padd = (Addition*) &d; // (Addition*) tells the compiler to explicitly convert a pointer (or reference) to another type.
    // cout << "RESULT: " << padd->result() ;

    /** DYNAMIC_CAST */
    // try {
    //     // Create a pointer to Base, but initialize it to a Derived object
    //     Base* pba = new Derived;  // This is valid because Derived is a subclass of Base
        
    //     // Create a pointer to Base, but initialize it to a Base object
    //     Base* pbb = new Base;  // This is a valid Base object

    //     // Declare a pointer to Derived
    //     Derived* pd;

    //     /** Dynamic cast to Derived* */
    //     // Cast pba (which points to a Derived object) to Derived* and assign it to pd
    //     pd = dynamic_cast<Derived*>(pba);
    //     // If the cast is successful, pd will point to the Derived object. If not, pd will be nullptr.
    //     if (pd == nullptr) {
    //         cout << "Null pointer on first type-cast 1.\n";  // This shouldn't be reached, because pba points to a Derived object
    //     } else {
    //         cout << "First type-cast successful.\n";  // Expected output: "First type-cast successful."
    //     }

    //     // Try casting pbb (which points to a Base object) to Derived*
    //     pd = dynamic_cast<Derived*>(pbb);
    //     // Since pbb points to a Base object (not a Derived object), the cast will fail and pd will be nullptr.
    //     if (pd == nullptr) {
    //         cout << "Null pointer on second type-cast 2.\n";  // Expected output: "Null pointer on second type-cast 2."
    //     } else {
    //         cout << "Second type-cast successful.\n";  // This won't be reached.
    //     }
    // }catch (exception& e) {
    //     // If any exception occurs during execution (e.g., memory allocation failure), catch it here.
    //     cout << "Exception: " << e.what();  // Prints the exception message
    // }

  /** STATIC_CAST */
    /** WRONG */
      // BaseV1 * a = new BaseV1;
      // DerivedV1 * b = static_cast<DerivedV1*>(a);
    /** CORRECT*/
      // BaseV1 * a = new DerivedV1;  // a points to a DerivedV1 object (not BaseV1)
      // DerivedV1 * b = static_cast<DerivedV1*>(a);  // This is now safe, since a actually points to DerivedV1

      // Do something with b
      // delete a;  // Don't forget to free the allocated memory

  /** REINTERPRET_CAST */
    // float f = 3.14f;
    // int* intPtr = reinterpret_cast<int*>(&f);

    // cout << "Bit pattern of float as int: " << *intPtr << endl;

  /** CONST_CAST */
  // const char *c = "sample text";  // `c` is a constant pointer to a string literal
  // print(const_cast<char *>(c));   // Remove constness from `c` using const_cast
  // char c1 = 'A';
  // cout << c1;

  /** TYPEID */
  //EXAMPLE #1 
  // int * a, b;
  // int * a, * b;
  // a=0; b=0;
  // char character = 'A';
  
  // cout << "character type: " << typeid(character).name() << endl;

  // if (typeid(a) != typeid(b))
  // {
  //   cout << "a and b are of different types:\n";
  //   cout << "a is: " << typeid(a).name() << '\n';
  //   cout << "b is: " << typeid(b).name() << '\n';
  // }

  //EXAMPLE #2
   try {
    BaseV3* a = new BaseV3;      // Pointer 'a' of type Base* pointing to a Base object
    BaseV3* b = new DerivedV3;   // Pointer 'b' of type Base* pointing to a Derived object
    
    // Using typeid with pointers to show the static type (the declared type of the pointer)
    cout << "a is: " << typeid(a).name() << '\n';   // Type of pointer 'a' (Base*)
    cout << "b is: " << typeid(b).name() << '\n';   // Type of pointer 'b' (Base*)

    // Using typeid with dereferenced objects to show the dynamic type (the actual object type at runtime)
    cout << "*a is: " << typeid(*a).name() << '\n';  // Type of object pointed to by 'a' (Base)
    cout << "*b is: " << typeid(*b).name() << '\n';  // Type of object pointed to by 'b' (Derived)
  } catch (exception& e) {
    cout << "Exception: " << e.what() << '\n';  // Catch any exceptions
  }
  return 0;
}