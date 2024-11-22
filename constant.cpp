#include <iostream>
using namespace std;
const double pi = 3.1415926;
const char newline = '\n';
#define NEWLINE '\n'
int main(){
    const int maxAttempts = 5;  // Declaring a constant integer

    std::cout << "Maximum attempts allowed: " << maxAttempts << std::endl;

    bool foo1 = true;
    bool bar1 = false;
    int* p = nullptr;

    cout << foo1 <<endl; 
    cout << bar1 <<endl;
    cout << p << newline;

    double r=5.0;               // radius
    double circle;
    
    circle = 2 * pi * r;
    cout << circle << newline;
    cout << newline;
    cout << NEWLINE;
    return 0;
}