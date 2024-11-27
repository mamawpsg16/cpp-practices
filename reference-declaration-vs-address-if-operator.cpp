#include<iostream>
using namespace std;

int main(){
    int a = 10;
    int& b = a;  // 'b' is a reference to 'a' Reference Declaration

    b = 20;  // Changes the value of 'a' to 20
    cout << a;  // Outputs 20

    int a1 = 10;
    int* ptr = &a1;  // 'ptr' stores the address of 'a' Address-of Operator

    cout << ptr << endl;  // Outputs the address of 'a'
    cout << *ptr << endl; // Dereferencing ptr, outputs 10 (the value stored at 'a')
    return 0;
}