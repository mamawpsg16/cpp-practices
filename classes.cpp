#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  public:
    Rectangle ();
    Rectangle (int,int); /** CONSTRUCTOR */
    void set_values (int,int);
    int area() {return width*height;}
};

// void Rectangle::set_values (int x, int y) {
//   width = x;
//   height = y;
// }

/** CONSTRUCTOR */
Rectangle::Rectangle (int a, int b) {
  width = a;
  height = b;
}

/** OVERLOADING CONSTRUCTOR */
Rectangle::Rectangle () {
  width = 5;
  height = 5;
}

/** UNIFORM INITIALIZATION  */
// class Circle {
//     double radius;
//   public:
//     Circle(double r) 
//     { 
//         radius = r; 
//     }
//     double circum() {return 2*radius*3.14159265;}
// };

/** MEMBER INITIALIZATION IN CONSTRUCTOR */
class Circle {
    double radius;
  public:
    Circle(double r) : radius(r) { }
    double area() {return radius*radius*3.14159265;}
};

class Cylinder {
    Circle base;
    double height;
  public:
    Cylinder(double r, double h) : base (r), height(h) {}
    double volume() {return base.area() * height;}
};

/** POINTER TO CLASSES */
class Person {
private:
    string name;
    int age;

public:
    // Constructor
    Person(string n, int a) : name(n), age(a) {}

    // Method to display details
    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};


 /** CLASSES DEFINED WITH STRUCT AND UNION */

 // STRUCT
 struct Car {
    string brand;
    int year;

    // Member function
    void showDetails() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

// UNION
union Measurement {
    int length;
    float weight;
    char grade;
};


// STRUCT + UNION
struct PaymentInfo {
    int employeeID;
    union {
        float hourlyRate; // For hourly employees
        float monthlySalary; // For salaried employees
    } payment;
    bool isHourly;

    void displayInfo() {
        cout << "Employee ID: " << employeeID << ", ";
        if (isHourly) {
            cout << "Hourly Rate: $" << payment.hourlyRate << endl;
        } else {
            cout << "Monthly Salary: $" << payment.monthlySalary << endl;
        }
    }
};


int main(){
    /** CLASS USAGE */
    // Rectangle rect, rectb;
    // rect.set_values(3,4);
    // rectb.set_values (5,6);
    // std::cout << "rect area: " << rect.area() << std::endl;
    // std::cout << "rectb area: " << rectb.area() << std::endl;

    /*** CONSTRUCTOR  */
    // Rectangle rect(3,4), rectb(5,6);
    // // Rectangle rect (3,4);
    // // Rectangle rectb (5,6);
    // // rect.set_values(3,4);
    // // rectb.set_values (5,6);
    // std::cout << "rect area: " << rect.area() << std::endl;
    // std::cout << "rectb area: " << rectb.area() << std::endl;

    /** OVERLOADING CONSTRUCTOR */
    // Rectangle rect (3,4);
    // Rectangle rectb;   // ok, default constructor called
    // Rectangle rectc(); // oops, default constructor NOT called 
    // std::cout << "rect area: " << rect.area() << std::endl;
    // std::cout << "rectb area: " << rectb.area() << std::endl;

    /** UNIFORM INITIALIZATION  */
    // Circle foo (10.0);   // functional form
    // Circle bar = 20.0;   // assignment init.
    // Circle baz {30.0};   // uniform init.
    // Circle qux = {40.0}; // POD-like

    // std::cout << "foo" << foo.circum() << std::endl; 
    // std::cout << "bar" << bar.circum() << std::endl; 
    // std::cout << "baz" << baz.circum() << std::endl; 
    // std::cout << "qux" << qux.circum() << std::endl; 

    /** MEMBER INITIALIZATION IN CONSTRUCTOR */
    // Cylinder foo (10,20);

    // std::cout << "foo's volume: " << foo.volume() << '\n';

    /** POINTER TO CLASSES */
    // DIFFERENT WAYS INITIALIZING POINTER TO CLASS
    // Person kevin("Kevin", 25); // Stack-allocated object
    // Person *person1, *person2, *person3;

    // person1 = &kevin; // Pointer to stack object
    // person2 = new Person("Dummy 1", 25); // Pointer to dynamically allocated object
    // person3 = new Person[1]{{"Dummy 3", 24}}; // Dynamically allocated array

    // // Use the pointer to call a class method
    // kevin.display();
    // person1->display();
    // person2->display();
    // person3[0].display(); // Access the array element explicitly

    
    // delete person2; // Free the dynamically allocated memory
    // delete[] person3; // Free memory allocated as an array

    /** CLASSES DEFINED WITH STRUCT AND UNION */

    // STRUCT
    // Car car1;
    // car1.brand = "Toyota";
    // car1.year = 2020;

    // car1.showDetails(); // Output: Brand: Toyota, Year: 2020

    // UNION
    // Measurement m;

    // m.length = 100; // Assigning length
    // cout << "Length: " << m.length << endl; // Output: Length: 100

    // m.weight = 65.5; // Overwriting length
    // cout << "Weight: " << m.weight << endl; // Output: Weight: 65.5

    // m.grade = 'A'; // Overwriting weight
    // cout << "Grade: " << m.grade << endl; // Output: Grade: A

    // // Accessing other members after overwriting
    // cout << "Length after grade assignment: " << m.length << endl; // Undefined behavior

    // STRUCT + UNION
    // PaymentInfo emp1;
    // emp1.employeeID = 101;
    // emp1.isHourly = true;
    // emp1.payment.hourlyRate = 25.5;

    // PaymentInfo emp2;
    // emp2.employeeID = 102;
    // emp2.isHourly = false;
    // emp2.payment.monthlySalary = 4500.0;

    // emp1.displayInfo(); // Output: Employee ID: 101, Hourly Rate: $25.5
    // emp2.displayInfo(); // Output: Employee ID: 102, Monthly Salary: $4500.0
    return 0;
}