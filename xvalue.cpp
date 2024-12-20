#include <iostream>
using namespace std;
// §8.3.2 
// References are either form of: 
// T& D         lvalue reference 
// T&& D        rvalue reference 
// They are distinct types (differentiating overloaded functions) 
  
// §8.5.3 
// The initializer of an rvalue reference shall not be an lvalue 
  
// lvalue references 
const int& lvr1{ 42 }; // value 
  
int lv1{ 0 }; 
int& lvr2{ lv1 }; // lvalue (non-const) 
  
constexpr int lv2{ 42 }; 
const int& lvr3{ lv2 }; // lvalue (const) 
  
constexpr int f1(int x) 
{ 
    return 6 * x; 
} 
const int& lvr4{ f1(7) }; // Function return value 
  
const int& lvr5{ (lv1 + f1(7)) / 2 }; // expression 
  
// rvalue references 
const int&& rvr1{ 42 }; // value 
  
// Enable next two statements to reveal compiler error 
#if 0 
int&& rvr2       {lv1}; // lvalue (non-const) 
const int&& rvr3  {lv2}; // lvalue (const) 
#else 
int&& rvr2{ static_cast<int&&>(lv1) }; // rvalue (non-const) 
const int&& rvr3{ static_cast<const int&&>(lv2) }; // rvalue (const) 
#endif 
const int&& rvr4{ f1(7) }; // Function return value 
const int&& rvr5{ (lv1 + f1(7)) / 2 }; // expression 
int main(){
    // int&  // lvalue reference
    // int&&  // rvalue reference
    // int f(int&);
    // int f(int&&);

    // int lv1         {42};
    // int& lvr        {lv1};    // Allowed
    // int&& rvr1      {lv1};   // Illegal
    // int&& rvr2      {static_cast<int&&>(lv1)};// Allowed


    lv1 = 42; 
    // Print out the references 
    cout << lvr1 << " Value" << endl; 
    cout << lvr2 << " lvalue (non-const)" << endl; 
    cout << lvr3 << " lvalue (const)" << endl; 
    cout << lvr4 << " Function return value" << endl; 
    cout << lvr5 << " Expression (temporary object)" << endl; 
  
    cout << rvr1 << " Value" << endl; 
    cout << rvr2 << " rvalue (const)" << endl; 
    cout << rvr3 << " rvalue (non-const)" << endl; 
    cout << rvr4 << " Function return value" << endl; 
    cout << rvr5 << " Expression (temporary object)" << endl; 
    return 0;
}