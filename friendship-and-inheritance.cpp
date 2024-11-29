#include <iostream>
using namespace std;

/** FRIEND FUNCTIONS */
class Rectangle {
    int width, height;  // private members that represent the dimensions of the rectangle
  public:
    // Default constructor
    Rectangle() {}

    // Parameterized constructor to initialize width and height
    Rectangle (int x, int y) : width(x), height(y) {}

    // Member function to calculate the area of the rectangle
    // int area() { return width * height; }
    int area();  // Member function declaration

    // Declare the function 'duplicate' as a friend, allowing it to access private members
    friend Rectangle duplicate (const Rectangle&);
};

// 'duplicate' is a friend function, so it can access the private members of 'Rectangle' class
// It simply has access to its private and protected members without being a member.
Rectangle duplicate (const Rectangle& param)
{
  Rectangle res;  // Create a new Rectangle object to store the result

  // Double the width and height of the given 'Rectangle' object
  res.width = param.width * 2;
  res.height = param.height * 2;

  // Return the newly created 'Rectangle' with doubled dimensions
  return res;
}

int Rectangle::area() { 
    return width * height; 
}


/** FRIEND CLASSES */
// Forward declaration of the 'Square' class so that 'Rectangle' can reference it
class Square;

class RectangleV1 {
    int width, height;  // Private members of Rectangle class
  public:
    // Member function to calculate the area of the rectangle
    int area() { return (width * height); }

    // Convert function that takes a Square object as argument
    void convert(Square a);  // This will be defined later
};

class Square {
    friend class RectangleV1;  // Rectangle class is a friend of Square
  private:
    int side;  // Private member to store the side length of the square
  public:
    // Constructor to initialize the side length of the square
    Square(int a) : side(a) {}
};

// Definition of the convert function of Rectangle class
void RectangleV1::convert(Square a) {
    width = a.side;  // Set the width of Rectangle to the side of Square
    height = a.side; // Set the height of Rectangle to the side of Square
}

/** INHERITANCE BETWEEN CLASSES */
class Base {
public:
    int publicMember;      // Accessible from anywhere (public)
protected:
    int protectedMember;   // Accessible within the class and derived classes (protected)
private:
    int privateMember;     // Accessible only within the class (private)
};

// Public Inheritance
class DerivedPublic : public Base {
    // publicMember remains public in DerivedPublic class.
    // protectedMember remains protected in DerivedPublic class.
    // privateMember is inaccessible in DerivedPublic class.

public:
    void accessBase() {
        // Accessing publicMember (accessible)
        publicMember = 10;

        // Accessing protectedMember (accessible in derived class)
        protectedMember = 20;

        // Accessing privateMember (inaccessible in derived class)
        // privateMember = 30;  // ERROR: privateMember is private in Base class
    }
};

// Protected Inheritance
class DerivedProtected : protected Base {
    // publicMember becomes protected in DerivedProtected class.
    // protectedMember remains protected in DerivedProtected class.
    // privateMember is inaccessible in DerivedProtected class.

public:
    void accessBase() {
        // Accessing publicMember (now protected in DerivedProtected class)
        publicMember = 10;

        // Accessing protectedMember (accessible in derived class)
        protectedMember = 20;

        // Accessing privateMember (inaccessible in derived class)
        // privateMember = 30;  // ERROR: privateMember is private in Base class
    }

    void print(){
        cout << "publicMember: " << publicMember << " protectedMember: " << protectedMember << endl;
    }
};

// Private Inheritance
class DerivedPrivate : private Base {
    // publicMember becomes private in DerivedPrivate class.
    // protectedMember becomes private in DerivedPrivate class.
    // privateMember is inaccessible in DerivedPrivate class.

public:
    void accessBase() {
        // Accessing publicMember (now private in DerivedPrivate class)
        publicMember = 10;

        // Accessing protectedMember (now private in DerivedPrivate class)
        protectedMember = 20;

        // Accessing privateMember (inaccessible in derived class)
        // privateMember = 30;  // ERROR: privateMember is private in Base class
    }
    void print(){
        cout << "publicMember: " << publicMember << " protectedMember: " << protectedMember << endl;
    }
};

/** INVOKING THE CONSTRUCTOR OF THE BASE CLASS */
class Mother {
    public:
        Mother () {
            cout << "Mother: no parameters\n";  // Default constructor
        }

        Mother (int a) {
            cout << "Mother: " << "int constructor = " << a  <<endl;  // Constructor with an int parameter
        }
};

class Daughter : public Mother {
    public:
        Daughter (int a) {
            cout << "Daughter: " << "int parameter constructor = " << a  <<endl ;
        }
};

class Son : public Mother {
    public:
        Son (int a) : Mother(a) {  // Calls the parameterized constructor of Mother
            cout << "Son: " << "int parameter constructor = " << a  <<endl ;
        }
};
/** MULTIPLE INHERITANCE */

class PolygonV1 {
protected:
    int width, height;
public:
    PolygonV1 (int a, int b) : width(a), height(b) {}
};

class Output {
public:
    static void print (int i);
};

void Output::print (int i) {
    cout << i << '\n';
}

class RectangleV2 : public PolygonV1, public Output {
public:
    RectangleV2 (int a, int b) : PolygonV1(a,b) {}  // Initializes PolygonV1 base class with a and b
    int area () { return width * height; }      // Calculates area of the rectangle
};

class Triangle : public PolygonV1, public Output {
public:
    Triangle (int a, int b) : PolygonV1(a,b) {}  // Initializes Polygon base class with a and b
    int area () { return width * height / 2; }  // Calculates area of the triangle
};

int main() {
    // Create two Rectangle objects
    // Rectangle foo;  // Default constructor, no size
    // Rectangle bar(2, 3);  // Parameterized constructor with width = 2 and height = 3
    
    // Call the friend function 'duplicate' to double the dimensions of 'bar'
    // foo = duplicate(bar);

    // Print the area of the 'foo' rectangle after duplication (should be 2*2 * 3*2 = 24)
    // cout << foo.area() << '\n';

    /** FRIEND CLASSES */
    // RectangleV1 rect;  // Create a Rectangle object
    // Square sqr(4);   // Create a Square object with side length 4

    // // Convert the Square to a Rectangle (Square becomes a Rectangle with equal width and height)
    // rect.convert(sqr);

    // // Output the area of the converted rectangle (area = 4 * 4 = 16)
    // cout << rect.area();  // Output should be 16

    /** INHERITANCE BETWEEN CLASSES */
    // Using DerivedPublic class (public inheritance)
    // DerivedPublic dp;
    // dp.accessBase();
    // cout << "DerivedPublic publicMember: " << dp.publicMember << endl;  // Accessible
    // cout << dp.protectedMember; // ERROR: Cannot access protectedMember from outside
    // cout << dp.privateMember;   // ERROR: Cannot access privateMember

    // Using DerivedProtected class (protected inheritance)
    // DerivedProtected dpr;
    // dpr.accessBase();
    // dpr.print();
    // cout << dpr.publicMember; // ERROR: publicMember is now protected
    // cout << dpr.protectedMember; // ERROR: Cannot access protectedMember from outside
    // cout << dpr.privateMember;   // ERROR: Cannot access privateMember

    // Using DerivedPrivate class (private inheritance)
    // DerivedPrivate dprv;
    // dprv.accessBase();
    // dprv.print();
    // cout << dprv.publicMember;  // ERROR: publicMember is now private
    // cout << dprv.protectedMember;  // ERROR: protectedMember is now private
    // cout << dprv.privateMember;    // ERROR: Cannot access privateMember

    /** WHAT IS INHERITED FROM THE BASE CLASS*/
        // EXCEPTIONS : 
        // its constructors and its destructor
        // its assignment operator members (operator=)
        // its friends
        // its private members

    /** INVOKING THE CONSTRUCTOR OF THE BASE CLASS */
    // Daughter kelly(1);  // Calls Daughter's constructor, which calls Mother() by default
    // Son bud(5);         // Calls Son's constructor, which calls Mother(0) explicitly

    /** MULTIPLE INHERITANCE */
    RectangleV2 rect(4, 5);   // Create a Rectangle object
    Triangle trgl(4, 5);    // Create a Triangle object
    
    rect.print(rect.area());        // Prints the area of the rectangle (using Output class method)
    Triangle::print(trgl.area());   // Prints the area of the triangle (using Output class method)
    return 0;
}