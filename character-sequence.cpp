#include <iostream>
#include <string>
#include <cstring> 
using namespace std;

int main(){
    string name = "Kevin Mensah";
    cout << name <<endl;

    /** CHARACTER SEQUENCES */
    // char foo[20];
    //  char foo[20] = "Hello MF";
    // strcpy(foo, "Hello MF"); 
    // cout << foo <<endl;

    /** INITIALIZATION OF NULL-TERMINATED CHARACTER SEQUENCES */
    // char myword[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    // char myword1[] = "Hello";
    // cout << myword << strlen(myword)<<endl;
    // cout << myword1  << strlen(myword) <<endl;

    /** STRINGS AND NULL-TERMINATED CHARACTER SEQUENCES */
    // Null-Terminated Character Sequences (C-Strings)
    char question1[] = "What is your name? ";
    char answer1[80];
    // C++ std::string Class
    string question2 = "Where do you live? ";
    string answer2;
    cout << question1;
    cin >> answer1;
    cout << question2;
    cin >> answer2;
    cout << "Hello, " << answer1;
    cout << " from " << answer2 << "!\n";
    return 0;
}
