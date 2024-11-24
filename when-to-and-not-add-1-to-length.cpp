#include <iostream>
using namespace std;
#include <cstring>

int main(){
    /** ADD + 1 TO LENGTH */ 
    
    //EXAMPLE #1  Allocating Memory for C-Style Strings - When manually allocating memory for a C-style string using new or malloc, you must add 1 to include the null terminator.
    // const char* msg = "hello";
    // size_t length = std::strlen(msg) + 1;  // Add 1 for '\0'
    // char* message = new char[length];     // Allocate memory for "hello\0"
    // std::strcpy(message, msg);            // Safe copy

    //EXAMPLE #2 Copying Strings -  When copying a string into a buffer, ensure the buffer can hold the string's characters plus the null terminator.
    // const char* source = "world";
    // char buffer[6];                     // 5 for characters + 1 for '\0'
    // std::strcpy(buffer, source);        // Safe

    //EXAMPLE#3  Concatenating Strings -  When concatenating strings, calculate the total length including space for the null terminator.
    // const char* first = "hello";
    // const char* second = "world";

    // size_t length = std::strlen(first) + std::strlen(second) + 1;  // +1 for '\0'
    // char* result = new char[length];
    // std::strcpy(result, first);
    // cout << result;
    // std::strcat(result, second); // Safe concatenation
    // cout << result;

    /**  WHEN NOT TO ADD + 1 */

    //EXAMPLE #1 When Using std::string - std::string automatically manages the null terminator for you;
    // std::string str = "hello"; // No need to add 1

    //EXAMPLE #2 (b) When Using std::strlen for Length Only - std::strlen returns the length of a string excluding the null terminator. If you’re only using this for calculations and not for memory allocation, you don’t need to add 1.
    // const char* msg = "hello";
    // size_t len = std::strlen(msg); // 5, no need to add 1


    //EXAMPLE #3  When Allocating Memory for Raw Buffers (Non-Strings) - If you’re allocating a raw buffer for data (not a string), there’s no need to add 1 for a null terminator.
    // int* data = new int[10]; // Allocating memory for 10 integers

    return 0;
}
