#include <iostream>

int main(){
    int a, b=3;
    int x = 0;
    int y = 3;
    int z;
    // z = ++y; //In Example 1, the value assigned to z is the value of y after being increased.
    z = y++; // it is the value y had before being increased.
    std::cout << "Z" << z <<std::endl;     
    x++;
    std::cout << "Zero" << x <<std::endl;     
    ++x;
    std::cout << "First" << x <<std::endl;     
    x+=1;
    std::cout << "Second" << x <<std::endl;     
    x=x+1;
    std::cout << "Third" << x <<std::endl;     

    a = b;
    a+=2;

    std::cout << a  <<std::endl;     

    std::cout << (7 == 5)  <<std::endl;   // evaluates to false
    std::cout << (5 > 4)   <<std::endl;   // evaluates to true
    std::cout << (3 != 2)  <<std::endl;   // evaluates to true
    std::cout << (6 >= 6)  <<std::endl;   // evaluates to true
    std::cout <<  (5 < 5)   <<std::endl;   // evaluates to false
    std::cout <<  (7==5 ? 4 : 3)   <<std::endl;   // evaluates to false

    /** Comma operator ( , )*/
    int a1 = (b=3, b+2);
    std::cout <<  a1   <<std::endl;   // evaluates to false

    /** Explicit type casting operator */
    int i1;
    float f1 = 3.14;
    i1 = (int) f1;

    std::cout <<  i1   <<std::endl;   // evaluates to false
    /** sizeof*/
    std::cout <<  sizeof(i1)   <<std::endl;   // evaluates to false

    /** Precedence of operators */
    int ab = 5 + 7 % 2; // = x = 5 + (7 % 2); 
    std::cout << ab <<std::endl;
    return 0;

}