#include <iostream>
using namespace std;


int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
//   g = (*functocall)(x, y); // Explicit dereference
  g = functocall(x, y);    // Implicit dereference (simpler and preferred)
  return (g);
}

void increment_all(int* start, int* stop)
{
  int* current = start;  // Pointer to the first element of the array
  while (current != stop) {
    ++(*current);  // Dereference current pointer to increment the value it points to
    ++current;     // Move the pointer to the next element in the array
  }
}


void print_all(const int* start, const int* stop)
{
  const int* current = start;  // Pointer to the first element of the array
  while (current != stop) {
    cout << *current << '\n';  // Print the value pointed to by `current`
    ++current;                // Move the pointer to the next element in the array
  }
}

/** VOID POINTERS */
void increase (void* data, int psize)
{
  if ( psize == sizeof(char) ){ 
    char* pchar;           // Declare a pointer to a char
    pchar = (char*) data;  // Explicitly cast `void*` to `char*`
    ++(*pchar);            // Dereference and increment the value

  }else if (psize == sizeof(int) ){ 
      // Cast the void pointer to an int pointer
        int* pint;
        pint= (int*)data;
        // Dereference and increment the value
        ++(*pint); 
  }
}

int main(){
    /** ADDRESS OF OPERATOR (&)*/
    // EXAMPLE USAGE
    // int myvar = 25;
    // int *foo = &myvar;  // foo is a pointer, so it can hold the address of myvar
    // int bar = myvar;    // bar stores the value of myvar (25)
    // cout << "foo: " << foo <<endl;
    // cout << "bar: " << bar <<endl;

    /** DEREFERENCE OPERATOR */
    // int myvar = 25;
    // int* foo = &myvar;  // foo holds the address of myvar
    // int baz = *foo;     // baz gets the value stored at the address foo is pointing to (25)
    // cout << "foo: " << *foo <<endl; //GET THE VALUE OF THE ADDRESS POINTED IN FOO
    // cout << "bar: " << baz <<endl;

    /** DECLARING POINTERS */
    //EXAMPLE USAGE 
    // int * number;
    // char * character;
    // double * decimals;
   
    // int firstvalue = 5, secondvalue = 15;
    // int * p1, * p2;

    // p1 = &firstvalue;  // p1 = address of firstvalue
    // p2 = &secondvalue; // p2 = address of secondvalue
    // *p1 = 10;          // value pointed to by p1 = 10
    // cout << "firstvalue is " << firstvalue << '\n';
    // *p2 = *p1;         // value pointed to by p2 = value pointed to by p1
    // cout << "secondvalue is " << secondvalue << '\n';
    // p1 = p2;           // p1 = p2 (value of pointer which is address)
    // cout << "firstvalue(2) is " << firstvalue << '\n';
    // *p1 = 20;          // value pointed to by p1 = 20
    // cout << "secondvalue(2) is " << secondvalue << '\n';
    
    // cout << "firstvalue is " << firstvalue << '\n';
    // cout << "secondvalue is " << secondvalue << '\n';

    /** POINTERS AND ARRAYS */
    // int numbers[5];
    // int * p;
    // // Point p to the first element of the numbers array
    // p = numbers;  
    // // Dereference the pointer to set the value of the first element of the array to 10
    // *p = 10;

    // // Increment the pointer p to point to the second element of the array
    // p++;  
    // // Set the value of the second element (now p points to numbers[1]) to 20
    // *p = 20;

    // // Make p point to the third element of the array directly by using the address of numbers[2]
    // p = &numbers[2];  
    // // Set the value of the third element to 30
    // *p = 30;

    // // Point p to the fourth element using pointer arithmetic (numbers + 3)
    // p = numbers + 3;  
    // // Set the value of the fourth element (numbers[3]) to 40
    // *p = 40;

    // // Set the fifth element (numbers[4]) using pointer arithmetic and dereferencing
    // p = numbers;  
    // *(p+4) = 50;  // equivalent to numbers[4] = 50

    // // Print the entire array to show the final values after all assignments
    // for (int n = 0; n < 5; n++)
    //     cout << numbers[n] << ", "; // Output the values in the numbers array

    /** POINTERS INITIALIZATION */
    // EXAMPLE USAGE
    // myptr = &myvar;
    // int *foo = &myvar;
    // int *bar = foo;

    /** POINTERS AND CONST */
    // EXAMPLE USAGE
    // int x;
    // int y = 10;
    // const int* p = &y;  // Pointer `p` can point to an integer, but cannot modify the value it points to
    // x = *p;  // OK: you can read the value that `p` points to (which is `y`)
    // *p = x;  // ERROR: you cannot modify the value that `p` points to because it's `const`

    // int numbers[] = {10,20,30};
    // increment_all (numbers,numbers+3);
    // print_all (numbers,numbers+3);

    // int x;
    // int *  p1 = &x;  // non-const pointer to non-const int
    // const int *  p2 = &x;  // non-const pointer to const int
    // int * const p3 = &x;  // const pointer to non-const int
    // const int * const p4 = &x;  // const pointer to const int 

    /** POINTERS AND STRING LITERALS */
    // const char * foo = "hello";
    // cout << foo[4];
    // cout << *(foo+3);

    /** POINTERS TO POINTERS */
    // int num = 10;                // A regular integer variable
    // int * ptr = &num;             // A pointer to the integer (points to the memory address of num)
    // int ** ptr_to_ptr = &ptr;     // A pointer to a pointer (points to the memory address of ptr)

    // printf("Value of num: %d\n", num);                  // Prints 10
    // printf("Value through ptr: %d\n", *ptr);            // Prints 10 (dereferencing ptr)
    // printf("Value through ptr_to_ptr: %d\n", **ptr_to_ptr); // Prints 10 (dereferencing ptr_to_ptr twice)

  /** VOID POINTERS */

    //EXAMPLE #1
    // int num = 42;
    // float pi = 3.14;
    // char letter = 'A';

    // // Void pointer
    // void* ptr;

    // // Point to different data types
    // ptr = &num;
    // cout << "Integer value: " << *(static_cast<int*>(ptr)) << endl;

    // ptr = &pi;
    // cout << "Float value: " << *(static_cast<float*>(ptr)) << endl;

    // ptr = &letter;
    // cout << "Char value: " << *(static_cast<char*>(ptr)) << endl;

    //EXAMPLE #2
    // char a = 'x';
    // int b = 1602;
    // increase (&a,sizeof(a));
    // increase (&b,sizeof(b));
    // cout << a << ", " << b << '\n'; 


     //EXAMPLE #3
    // int num = 10;
    // float f = 3.14;
    // void* ptr; // Declaring a void pointer

    // ptr = &num; // Storing the address of an integer
    // cout << "Integer value: " << *(static_cast<int*>(ptr)) << endl;

    // ptr = &f; // Storing the address of a float
    // cout << "Float value: " << *(static_cast<float*>(ptr)) << endl;

    /** NULL POINTERS*/
    // int* ptr = nullptr; // Pointer is initialized to "null"
    // int * p = 0;
    // int * r = NULL; // Defined as an alias of some null pointer constant value (such as 0 or nullptr).


    // if (ptr == nullptr) { // Check if the pointer is null
    //     cout << "Pointer is null and not pointing to anything." << endl;
    // }

    /** INVALID POINTERS*/
    // int* ptr; // Pointer is declared but not initialized
    // cout << *ptr; // Uncommenting this will cause undefined behavior

    /** DANGLING POINTER */
    //   int* ptr = new int(42); // Dynamically allocate memory
    // delete ptr;             // Free the memory
    // Now, `ptr` is dangling because it still "points" to the freed memory

    // Using the pointer after deleting is dangerous:
    // *ptr = 10; // Uncommenting this causes undefined behavior

    // ptr = nullptr; // Fix: Reset pointer to null after deleting

    /** POINTERS TO FUNCTION */
    // int m,n;
    // int (*minus)(int,int) = subtraction;

    // m = operation (7, 5, addition);
    // n = operation (20, m, minus);
    // cout <<n;

    return 0;
}