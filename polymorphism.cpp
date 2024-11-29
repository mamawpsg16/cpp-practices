#include<iostream>
using namespace std;

/** POINTERS TO BASE CLASS */
// Base class Polygon that has protected attributes for width and height
class Polygon {
  protected:
    int width, height; // The dimensions of the polygon (width and height)

  public:
    // A method to set the width and height values for a polygon
    void set_values(int a, int b) {
        width = a; // Set width to the value of 'a'
        height = b; // Set height to the value of 'b'
    }
};

// Rectangle class that inherits from Polygon
class Rectangle : public Polygon {
  public:
    // Method to calculate the area of a rectangle
    int area() {
        return width * height; // Area = width * height
    }
};

// Triangle class that also inherits from Polygon
class Triangle : public Polygon {
  public:
    // Method to calculate the area of a triangle
    int area() {
        return width * height / 2; // Area = (width * height) / 2 (half of rectangle's area)
    }
};

/** VIRTUAL MEMBERS */
/** Base class with a virtual `area()` method */
class PolygonV1 {
  protected:
    int width, height; // Common attributes for all polygons

  public:
    // Method to set the width and height of the polygon
    void set_values(int a, int b) {
        width = a; 
        height = b;
    }

    // Virtual function for calculating the area
    // Default implementation in base class returns 0
    virtual int area() { 
        return 0; 
    }
};

/** Derived class RectangleV1, inherits from PolygonV1 */
class RectangleV1 : public PolygonV1 {
  public:
    // Override the area() method to calculate the area of a rectangle
    int area() {
        return width * height;
    }
};

/** Derived class TriangleV1, inherits from PolygonV1 */
class TriangleV1 : public PolygonV1 {
  public:
    // Override the area() method to calculate the area of a triangle
    int area() { 
        return (width * height) / 2;
    }
};
 /** ABSTRACT BASE CLASSES */

// Abstract class (contains at least one pure virtual function)
// it can be used to create pointers to it 
class AbstractPolygon {
  protected:
    int width, height; // Dimensions common to all polygons

  public:
    // Method to set the width and height
    void set_values(int a, int b) {
        width = a;
        height = b;
    }

    // Pure virtual function: forces derived classes to implement this function
    virtual int area() = 0;

    // Method to print the area; it calls the pure virtual function `area()`
    void printarea() {
        // `this->area()` dynamically calls the correct derived class's implementation
        cout << this->area() << '\n';
    }
};

// Derived class for rectangles
class RectangleV2 : public AbstractPolygon {
  public:
    // Implementation of the pure virtual function for Rectangle
    int area() {
        return (width * height); // Area of rectangle: width * height
    }
};

// Derived class for triangles
class TriangleV2 : public AbstractPolygon {
  public:
    // Implementation of the pure virtual function for Triangle
    int area() {
        return (width * height / 2); // Area of triangle: (width * height) / 2
    }
};

// Abstract base class for polygons
class AbstractPolygonV2 {
  protected:
    int width, height;  // Dimensions of the polygon (width and height)

  public:
    // Constructor to initialize width and height
    AbstractPolygonV2(int a, int b) : width(a), height(b) {}

    // Pure virtual function, meaning this class is abstract and cannot be instantiated directly
    // Derived classes must implement the area function
    virtual int area(void) = 0;  

    // Print the area using the area function (polymorphic call)
    void printarea() {
        cout << this->area() << '\n';  // Calls the area function of the derived class
    }
};

// Derived class representing a Rectangle
class RectangleV3 : public AbstractPolygonV2 {
  public:
    // Constructor for Rectangle, which initializes the base class AbstractPolygonV2
    // with width and height
    RectangleV3(int a, int b) : AbstractPolygonV2(a, b) {}

    // Overriding the area function to return the area of a rectangle
    int area() {
        return width * height;  // Area = width * height for a rectangle
    }
};

// Derived class representing a Triangle
class TriangleV3 : public AbstractPolygonV2 {
  public:
    // Constructor for Triangle, which initializes the base class AbstractPolygonV2
    // with width and height
    TriangleV3(int a, int b) : AbstractPolygonV2(a, b) {}

    // Overriding the area function to return the area of a triangle
    int area() {
        return (width * height) / 2;  // Area = (width * height) / 2 for a triangle
    }
};
int main(){
    /** POINTERS TO BASE CLASS */
    // Create objects of Rectangle and Triangle
    // Rectangle rect;  // Rectangle object
    // Triangle trgl;   // Triangle object

    // Create pointers to the base class Polygon
    /**  A base class pointer (Polygon*) can only access members defined in the base class. */
    // Polygon *ppoly1 = &rect; // Pointer to Polygon, pointing to the Rectangle object
    // Polygon *ppoly2 = &trgl; // Pointer to Polygon, pointing to the Triangle object

    // Set width and height for both shapes using the set_values method
    // ppoly1->set_values(4, 5); // Set width=4, height=5 for Rectangle
    // ppoly2->set_values(4, 5); // Set width=4, height=5 for Triangle

    // Print the area of the rectangle using the Rectangle class method
    // cout << rect.area() << '\n'; // Outputs 20 (4 * 5)

    // Print the area of the triangle using the Triangle class method
    // cout << trgl.area() << '\n'; // Outputs 10 ((4 * 5) / 2)

    /** VIRTUAL MEMBERS */
     // Create objects of derived classes and the base class
    // RectangleV1 rect;   // Rectangle object
    // TriangleV1 trgl;    // Triangle object
    // PolygonV1 poly;     // Polygon object (base class)

    // Create pointers to the base class and assign them to derived class objects
    // PolygonV1* ppoly1 = &rect;  // Points to a RectangleV1 object
    // PolygonV1* ppoly2 = &trgl; // Points to a TriangleV1 object
    // PolygonV1* ppoly3 = &poly;  // Points to a PolygonV1 object

    // Use the base class pointer to set the width and height for each object
    // ppoly1->set_values(4, 5);  // Sets width=4, height=5 for Rectangle
    // ppoly2->set_values(4, 5);  // Sets width=4, height=5 for Triangle
    // ppoly3->set_values(4, 5);  // Sets width=4, height=5 for the base Polygon

    // Call the area() method using base class pointers
    // cout << ppoly1->area() << '\n';  // Calls RectangleV1::area() → Outputs 20
    // cout << ppoly2->area() << '\n';  // Calls TriangleV1::area() → Outputs 10
    // cout << ppoly3->area() << '\n';  // Calls PolygonV1::area() → Outputs 0

    /** ABSTRACT BASE CLASSES */
    //EXAMPLE #1
    // Create objects of derived classes
    // RectangleV2 rect;   // Rectangle object
    // TriangleV2 trgl;    // Triangle object

    // Create pointers to the abstract class and assign derived class objects
    // AbstractPolygon* ppoly1 = &rect;  // Points to a Rectangle object
    // AbstractPolygon* ppoly2 = &trgl; // Points to a Triangle object

    // Set the dimensions using the abstract class pointer
    // ppoly1->set_values(4, 5); // Sets width=4, height=5 for Rectangle
    // ppoly2->set_values(4, 5); // Sets width=4, height=5 for Triangle

    // Call the area() method through the abstract class pointer
    // cout << ppoly1->area() << '\n';  // Calls RectangleV2::area() → Outputs 20
    // cout << ppoly2->area() << '\n';  // Calls TriangleV2::area() → Outputs 10

    // Call the printarea() method, which internally calls the area() method
    // ppoly1->printarea(); // Outputs 20 (Rectangle area)
    // ppoly2->printarea(); // Outputs 10 (Triangle area)

    //EXAMPLE #2
    // Dynamically allocating memory for a Rectangle and a Triangle object
    // AbstractPolygonV2 *ppoly1 = new RectangleV3(4, 5);  // Creates a Rectangle with width=4 and height=5
    // AbstractPolygonV2 *ppoly2 = new TriangleV3(4, 5);   // Creates a Triangle with width=4 and height=5

    // Calling the printarea function, which in turn calls the area function of the derived classes
    // ppoly1->printarea();  // Outputs the area of the Rectangle (4 * 5 = 20)
    // ppoly2->printarea();  // Outputs the area of the Triangle (4 * 5 / 2 = 10)

    // Deleting dynamically allocated memory
    // delete ppoly1;  // Deallocates memory used by the Rectangle
    // delete ppoly2;  // Deallocates memory used by the Triangle
    return 0;
}