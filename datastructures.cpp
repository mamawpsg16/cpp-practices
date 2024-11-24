#include <iostream>  // For input and output operations
#include <string>    // For handling strings
#include <sstream>   // For stringstream (string-to-type conversion)
using namespace std;

/** REAL EXAMPLE #1 */
// Define a structure `movies_t` to represent a movie
struct movies_t {
  string title; // Property to store the title of the movie
  int year;     // Property to store the release year of the movie
} mine, yours;  // Declare two instances of the `movies_t` struct: `mine` and `yours`

// Function declaration to print movie details
void printmovie (movies_t movie); //Function Declaration (Prototype):

struct movies_tV1 {
  string title; // Property to store the movie title
  int year;     // Property to store the release year
} films[3];     // Declare an array of 3 `movies_tV1` structures named `films`


struct friends_t {
    string name;
    string email;
    movies_t favorite_movie;
} charlie, maria;

// Function declaration to print the details of a single movie
void printmovieV1 (movies_tV1 movie);

int main(){
    // Commented examples showing alternative ways to declare structs
    // EXAMPLE USAGE #1
    // struct product {
    //     int weight;
    //     double price;
    // } ;

    // product apple;
    // product banana, melon;

    // EXAMPLE USAGE #2
    // struct product {
    // int weight;
    // double price;
    // } apple, banana, melon;

    // REAL EXAMPLE #1
    // string mystr;  // Temporary string variable to hold input before converting it

    // // Initialize the `mine` instance with preset values
    // mine.title = "2001 A Space Odyssey"; // Assign a title to `mine`
    // mine.year = 1968;                    // Assign a year to `mine`

    // // Get user input for the `yours` instance
    // cout << "Enter title: ";              // Prompt the user to enter the movie title
    // getline (cin, yours.title);           // Read the entire line and store it in `yours.title`
    // cout << "Enter year: ";               // Prompt the user to enter the movie year
    // getline (cin, mystr);                 // Read the entire line into the temporary string `mystr`
    // stringstream(mystr) >> yours.year;    // Convert `mystr` to an integer and assign it to `yours.year`

    // // Display the details of the `mine` movie
    // cout << "My favorite movie is:\n ";
    // printmovie (mine);

    // // Display the details of the `yours` movie
    // cout << "And yours is:\n ";
    // printmovie (yours);

    // REAL EXAMPLE #2
    // string mystr; // Temporary string variable for input
    // int n;        // Loop variable to iterate through the array

    // // Input loop: Collect details for 3 movies
    // for (n = 0; n < 3; n++) {
    //     cout << "Enter title: ";          // Prompt the user to enter the title
    //     getline(cin, films[n].title);     // Read the title and store it in `films[n].title`

    //     cout << "Enter year: ";           // Prompt the user to enter the release year
    //     getline(cin, mystr);              // Read the input as a string into `mystr`
    //     stringstream(mystr) >> films[n].year; // Convert the string to an integer and store it in `films[n].year`
    // }

    // // Output loop: Display the details of the entered movies
    // cout << "\nYou have entered these movies:\n";
    // for (n = 0; n < 3; n++) {
    //     printmovieV1(films[n]); // Call `printmovieV1` to print the details of each movie
    // }

    /** POINTERS TO STRUCTURE */
    // string mystr;

    // movies_t amovie;
    // movies_t * pmovie;
    // pmovie = &amovie;

    // cout << "Enter title: ";
    // getline (cin, pmovie->title);
    // cout << "Enter year: ";
    // getline (cin, mystr);
    // (stringstream) mystr >> pmovie->year;

    // cout << "\nYou have entered:\n";
    // cout << pmovie->title;
    // cout << " (" << pmovie->year << ")\n";
    // cout << amovie.title;
    // cout << " (" << amovie.year << ")\n";

    /** NESTING STRUCTURES */
    // friends_t * pfriends = &charlie;
    // string name;
    // cout <<"What is your name?";
    // getline(cin, name);
    // cout << "Your name is:" << name <<endl;
    // pfriends->name = "Abc";
    // cout << pfriends->name;
    return 0;  // End of the program
}

// Function definition to print movie details
// Takes a `movies_t` struct as an argument
void printmovie (movies_t movie) { // Function Definition:
  cout << movie.title;        // Print the movie title
  cout << " (" << movie.year << ")\n"; // Print the release year in parentheses
}

void printmovieV1 (movies_tV1 movie) {
  cout << movie.title;        // Print the movie title
  cout << " (" << movie.year << ")\n"; // Print the release year in parentheses
}