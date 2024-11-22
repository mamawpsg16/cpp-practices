#include <iostream>
using namespace std;

int addition (int a, int b)
{
  int r;
  r=a+b;
  return r;
}

int subtraction (int a, int b)
{
  int r;
  r=a-b;
  return r;
}

void printmessage ()
{
  cout << "I'm a function!";
}

void duplicate (int& a, int& b, int& c)
{
  a*=2;
  b*=2;
  c*=2;
}
string concatenate (string a, string b){
    return a+b;
}
// DONT ALSO THIS 
string concatenateV1 (string& a, string& b){
    
    return a +b;
}
// SHOULD BE : 
/** Use const string& for read-only parameters to avoid unnecessary copies and to make the intent clear that the strings should not be modified inside the function.*/
string concatenateV2 (const string& a, const string& b)
{
  return a + " " + b;
}

inline int add(int a, int b) {
    return a + b;
}

int divide(int a, int b=2)
{
  int r;
  r=a/b;
  return (r);
}

void odd (int x);
void even (int x);

long factorial (long a)
{
  if (a > 1)
   return (a * factorial (a-1));
  else
   return 1;
}

int main ()
{
//   int z;
//   z = addition (5, 3);
//   cout << "The result is " << z << '\n';

//   int a=5, b=3, c;
//   c = subtraction (7,2);
//   cout << "The first result is " << c << '\n';

/** VOID RETURN  TYPE*/
// printmessage ();

/** ARGUMENTS PASSED BY VALUE && REFERENCE*/
    // int x=1, y=3, z=7;
    // duplicate (x, y, z);
    // cout << "x=" << x << ", y=" << y << ", z=" << z;

/** EFFICIENCY CONSIDERATION AND CONST REFERENCE*/
    // string a = "Hello";
    // string b = "World"; 
    // string c;
    // c = concatenateV2(a, b);
    // cout << c <<endl;
    // cout << "a = " << a << " b = " << b <<endl;

/** INLINE FUNCTIONS (FOR SMALL FUNCTIONS)*/
    // int d = 0;
    // d = add(5, 6);
    // cout << d << endl;

/** DEFAULT VALUE PARAMETERS*/
    // cout << divide(12) << '\n';
    // cout << divide(20,4) << '\n';

/** DECLARING FUNCTIONS */
    // int i;
    // do {
    //     cout << "Please, enter number (0 to exit): ";
    //     cin >> i;
    //     odd (i);
    // } while (i!=0);

/** RECURSIVITY*/
    long number = 9;
    cout << number << "! = " << factorial (number);
    return 0;
}

void odd (int x)
{
  if ((x%2)!=0) cout << "It is odd.\n";
  else even (x);
}

void even (int x)
{
  if ((x%2)==0) cout << "It is even.\n";
  else odd (x);
}