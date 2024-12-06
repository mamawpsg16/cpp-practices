// why there is no delete of resource in this because theres no dynamic memory ?
// ANSWER : In this program, there is no explicit dynamic memory allocation (e.g., using new or malloc), so no explicit deallocation (e.g., using delete or free) is necessary.

// CPP Program to demonstrate the use of copy constructor
// and assignment operator
#include <iostream>
#include <stdio.h>
using namespace std;

class Test {
public:
    Test() {}
    Test(const Test& t)
    {
        cout << "Copy constructor called " << endl;
    }

    Test& operator=(const Test& t)
    {
        cout << "Assignment operator called " << endl;
        return *this;
    }
};

// Driver code
int main()
{
    Test t1, t2;
    t2 = t1;
    Test t3 = t1;
    getchar();
    return 0;
}