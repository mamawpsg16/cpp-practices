#include <iostream>
#include <string>
using namespace std;
int main(){
    /**  WHILE */
    // int number = 10;
    // int number1 = 3;
    // int number2 = 0;
    // number2 = number1++;
    // number2 = ++number1;
    // std::cout << number2;
    // while (number > 0)
    // {
    //     std::cout << number << std::endl;
    //     --number;
    // }
    
    // std::cout << "Done" << std::endl;

    /** DO WHILE*/
    // string text;
    // do {
    //     cout << "Enter text: ";
    //     getline(cin, text);  // getline to avoid ambiguity
    //     cout << "You entered: " << text << endl;
    // } while (text != "goodbye");  // Loop until the user enters "goodbye"
    
    /** FOR LOOP*/
    // for (int n=10; n>0; n--) {
    //     cout << n << ", ";
    // }
    // cout << "liftoff!\n";
    
    // for (int n = 0, i = 100; n != i; ++n, --i)
    // {
    //     cout << "n = " << n << " i = " << i << endl;
    // }

    /** RANGE BASED */
    // string str {"Hello!"};
    // for (char c : str)
    // {
    //     cout << "[" << c << "]";
    // }

    // cout << '\n';
    // int numbers[] = {1,2,3,4,5};
    // for (int number : numbers)
    // {
    //     cout << number <<endl;
    // }

    /** JUMP STATEMENTS */
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << i <<endl;
    //     if(i == 3){
    //         cout << "Already Reached 3 Ending the LOOP";
    //         break;
    //     }

    // }

    // for (int i = 0; i < 10; i++)
    // {
    //     if(i == 5){
    //         continue;
    //     }
    //     cout << i <<endl;

    // }

    /** GOTO STATEMENT */
    // int n=10;
    // mylabel:
    //     cout << n << ", ";
    //     n--;
    // if (n>0) goto mylabel;
    // cout << "liftoff!\n";

    /** SWITCH */
    int number = 5;
    switch (number)
    {
    case 1:
        cout << "Number is :1";
        break;
    
    default:
        cout << "Value of Number is unknown";
        break;
    }
    return 0; 
}