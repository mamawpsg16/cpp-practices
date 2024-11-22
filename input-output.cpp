#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    // int number;
    // cout << "Choose a number (between 1 to 5): ";
    // cin >> number;
    //   if (number >= 1 && number <= 5) {
    //     cout << "The number is between 1 and 5. number:" << number << endl;
    // } else {
    //     clog << "The number is not between 1 and 5." << endl;
    // }

    /** cin and strings */

    string mystr;
    // cout << "What's your name? ";
    // getline (cin, mystr);
    // cout << "Hello " << mystr << ".\n";
    // cout << "What is your favorite team? ";
    // getline (cin, mystr);
    // cout << "I like " << mystr << " too!\n";

    /** stringstream*/
    // string data = "100 3.14";
    // istringstream iss(data);

    // int num;
    // double pi;
    // string word;

    // iss >> num >> pi >> word;  // Read from the string as if it's a stream
    // cout << num << " " << pi << " " << word << endl;  // Output: 100 3.14 hello

    // ostringstream oss; // -concatenating multiple parts or mixing different types (like string and int) without needing manual conversions or complex operations. It avoids messy code like

    // oss << "The answer is: " << 42;  // Write to the stream
    // string result = oss.str();       // Retrieve the constructed string
    // cout << result << endl;          // Output: The answer is: 42
    
    string mystr;
    float price=0;
    int quantity=0;

    cout << "Enter price: ";
    getline (cin,mystr);
    stringstream(mystr) >> price;
    cout << "Enter quantity: ";
    getline (cin,mystr);
    stringstream(mystr) >> quantity;
    cout << "Total price: " << price*quantity << endl;
    return 0;
}