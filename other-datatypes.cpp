#include <iostream>
#include <string.h>  // For strcpy
// #include <cstring>
using namespace std;

// Define a union for different types of messages
union MessageData {
    int integerData;
    float floatData;
    char stringData[50];
};

struct Message {
    int messageType;  // 0 for integer, 1 for float, 2 for string
    MessageData data; // Union to store data
};

struct book1_t {
    char title[50];
    char author[50];
    union {
        float dollars;
        int yen;
    } price;
};


struct book2_t {
    char title[50];
    char author[50];
    union {
        float dollars;
        int yen;
    };
};

// Define an enumerated type called 'Day'
enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

enum months_t { january = 1, february, march, april,
                may, june, july, august,
                september, october, november, december } y2k;

enum GameState { MainMenu, Playing, Paused, GameOver };

enum ErrorCode { Success = 0, FileNotFound, InvalidInput, NetworkError };

// Define an enum class for AccessLevel
enum class AccessLevel { Admin = 1, User, Guest };

enum class Colors {black=1, blue, green, cyan, red, purple, yellow, white};
enum class EyeColor : char { blue = 'B', green = 'G', Pink = 'P' };
string colorToString(Colors color) {
    switch(color) {
        case Colors::red: return "Red";
        case Colors::green: return "Green";
        case Colors::blue: return "Blue";
        default: return "Unknown";
    }
}

int main(){
    /** TYPE ALIASES (typedef / using)*/
    // typedef char C;
    // typedef unsigned int WORD;
    // typedef char * pChar;
    // typedef char field [50];

    // C mychar, anotherchar, *ptc1;
    // WORD myword;
    // pChar ptc2;
    // field name;
    
    // mychar = 'K';
    // cout << "mychar: " << mychar << endl;

    // anotherchar = 11;
    // cout << "anotherchar (as integer): " << (int)anotherchar << endl;

    // ptc2 = &mychar;
    // cout << "ptc2 points to: " << *ptc2 << endl;

    // // Using ptc1 to point to mychar and dereference to print its value
    // ptc1 = &mychar;
    // cout << "ptc1 points to: " << *ptc1 << endl;

    // strcpy(name, "Hello Motherfucker");
    // cout << "name: " << name << endl;

    // // Using myword to store and display an unsigned integer value
    // myword = 123456;
    // cout << "myword: " << myword << endl;

    /* USING */
    // USAGE
    // using CharType = char;           // CharType is a synonym for char
    // using WordType = unsigned int;   // WordType is a synonym for unsigned int
    // using CharPointer = char*;       // CharPointer is a synonym for char*
    // using FieldArray = char[50];     // FieldArray is a synonym for a char array of size 50

    //  CharType myChar, anotherChar, *ptrToChar;
    // WordType myWord;
    // CharPointer ptrToChar2;
    // FieldArray name;
    
    // myChar = 'K';
    // cout << "myChar: " << myChar << endl;

    // anotherChar = 11;
    // cout << "anotherChar (as integer): " << (int)anotherChar << endl;

    // ptrToChar2 = &myChar;
    // cout << "ptrToChar2 points to: " << *ptrToChar2 << endl;

    // ptrToChar = &myChar;
    // cout << "ptrToChar points to: " << *ptrToChar << endl;

    // strcpy(name, "Hello Motherfucker");
    // cout << "name: " << name << endl;

    // myWord = 123456;
    // cout << "myWord: " << myWord << endl;

    /** UNIONS */
    //EXAMPLE #1
    // union Data {
    //     int i;      // Integer type
    //     float f;    // Float type
    //     char str[20]; // String type (array of characters)
    // };

    // // Creating a union variable
    // Data data;

    // // Storing an integer value
    // data.i = 10;
    // cout << "data.i: " << data.i << endl;

    // // Storing a float value
    // data.f = 220.5;
    // cout << "data.f: " << data.f << endl; // This will overwrite data.i

    // // Storing a string value
    // strcpy(data.str, "Hello, World!");
    // cout << "data.str: " << data.str << endl; // This will overwrite data.f

    // // Showing the result of overwriting
    // cout << "data.i after storing string: " << data.i << endl; // This will show garbage value

    //EXAMPLE #2
    // Message msg1;
    // msg1.messageType = 0;  // Integer data
    // msg1.data.integerData = 42;

    // if (msg1.messageType == 0) {
    //     cout << "Integer Data: " << msg1.data.integerData << endl;
    // }

    // // Now, let's assign a float value
    // Message msg2;
    // msg2.messageType = 1;  // Float data
    // msg2.data.floatData = 3.14f;

    // if (msg2.messageType == 1) {
    //     cout << "Float Data: " << msg2.data.floatData << endl;
    // }

    // // Now, let's assign a string value
    // Message msg3;
    // msg3.messageType = 2;  // String data
    // strcpy(msg3.data.stringData, "Hello, C++!");

    // if (msg3.messageType == 2) {
    //     cout << "String Data: " << msg3.data.stringData << endl;
    // }

    /** ANONYMOUSE UNIONS */
    // book1_t book1;
    // strcpy(book1.title, "The C++ Programming Language");
    // strcpy(book1.author, "Bjarne Stroustrup");
    // book1.price.dollars = 39.99;

    // cout << "Book1 Title: " << book1.title << endl;
    // cout << "Book1 Author: " << book1.author << endl;
    // cout << "Book1 Price (in dollars): $" << book1.price.dollars << endl;

    // book2_t book2;
    // strcpy(book2.title, "Effective C++");
    // strcpy(book2.author, "Scott Meyers");
    // book2.dollars = 29.99;  // Directly access the member of the anonymous union

    // cout << "\nBook2 Title: " << book2.title << endl;
    // cout << "Book2 Author: " << book2.author << endl;
    // cout << "Book2 Price (in dollars): $" << book2.dollars << endl;

    /** ENUMERATED TYPES (ENUM)*/
    //EXAMPLE #1
     // Declare a variable of type 'Day'
    // Day today = Wednesday;

    // // Output the numeric value associated with 'Wednesday'
    // cout << "Numeric value of Wednesday: " << today << endl;

    // // Use a switch statement to print the name of the day
    // switch (today) {
    //     case Sunday:
    //         cout << "Today is Sunday" << endl;
    //         break;
    //     case Monday:
    //         cout << "Today is Monday" << endl;
    //         break;
    //     case Tuesday:
    //         cout << "Today is Tuesday" << endl;
    //         break;
    //     case Wednesday:
    //         cout << "Today is Wednesday" << endl;
    //         break;
    //     case Thursday:
    //         cout << "Today is Thursday" << endl;
    //         break;
    //     case Friday:
    //         cout << "Today is Friday" << endl;
    //         break;
    //     case Saturday:
    //         cout << "Today is Saturday" << endl;
    //         break;
    // }
    // //EXAMPLE #2
    // y2k = february;

    // // Print the numeric value of february
    // cout << "The numeric value of February: " << y2k << endl;

    // // Output the month based on the enum value
    // if (y2k == february) {
    //     cout << "It's February!" << endl;
    // }

    //EXAMPLE #3
    // void checkAccess(AccessLevel level) {
    //     switch(level) {
    //         case Admin: 
    //             cout << "Full access granted."; 
    //             break;
    //         case User: 
    //             cout << "Limited access granted."; 
    //             break;
    //         case Guest: 
    //             cout << "Read-only access."; 
    //             break;
    //         default:
    //             cout << "Invalid access level."; // Optional: in case of an invalid value
    //             break;
    //     }
    // }

    /** ENUMERATED TYPES WITH ENUM CLASS*/
    Colors mycolor;
 
    mycolor = Colors::blue;
    if (mycolor == Colors::green) mycolor = Colors::red;
    cout << colorToString(mycolor) << endl; 


     EyeColor color = EyeColor::blue;
    // Print the underlying char value of the enum
    cout << static_cast<char>(color) << endl;
    return 0;
}