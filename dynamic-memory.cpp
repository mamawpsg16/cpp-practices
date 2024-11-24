
#include <iostream>
#include <cstring> // For strcpy

using namespace std;

class LogMessage {
    char* message;

public:
    // Constructor
    LogMessage(const char* msg) {
        size_t length = std::strlen(msg) + 1; //Adding +1 to account for the null terminator ensures that:
        message = new (std::nothrow) char[length]; // Use no-throw for safety
        if (message) {
            std::strcpy(message, msg); // Copy the log message
        } else {
            std::cerr << "Failed to allocate memory for log message.\n";
        }
    }

    // Destructor
    ~LogMessage() {
        delete[] message; // Free allocated memory
    }

    void print() const {
        if (message) {
            std::cout << "Log: " << message << "\n";
        } else {
            std::cout << "No message to display.\n";
        }
    }
};

int main(){
    /** OPERATORS NEW AND NEW[] */
    //EXAMPLE
    // int * foo1;
    // int* p = new int(10); // Dynamically allocate an integer and initialize it to 10.
    // int* arr = new int[5]; // Dynamically allocate an array of 5 integers.
    // delete p;       // For single objects
    // delete[] arr;     // For arrays

     // Example 1: Single log message using `new`
    // LogMessage* log = new (std::nothrow) LogMessage("System started.");
    // if (log) {
    //     log->print();
    //     delete log; // Clean up
    // } else {
    //     std::cerr << "Failed to allocate memory for single log.\n";
    // }

    // // Example 2: Multiple log messages using `new[]`
    // const size_t logCount = 3;
    // LogMessage* logs = new (std::nothrow) LogMessage[logCount] {
    //     LogMessage("User logged in."),
    //     LogMessage("User performed action."),
    //     LogMessage("System shutting down.")
    // };

    // if (logs) {
    //     for (size_t i = 0; i < logCount; ++i) {
    //         logs[i].print();
    //     }
    //     delete[] logs; // Clean up
    // } else {
    //     std::cerr << "Failed to allocate memory for multiple logs.\n";
    // }

    /** OPERATORS DELETE AND DELETE[]*/
    int i,n;
    int * p;
    cout << "How many numbers would you like to type? ";
    cin >> i;
    p= new (nothrow) int[i];
    if (p == nullptr){
        cout << "Error: memory could not be allocated";
    }else{
        for (n=0; n<i; n++){
            cout << "Enter number: ";
            cin >> p[n];
        }
        cout << "You have entered: ";
        for (n=0; n<i; n++){
            cout << p[n] << ", ";
        }
        delete[] p;
    }
    return 0;
}