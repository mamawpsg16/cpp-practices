#include <iostream>
#include <fstream>  // For file handling
#include <string>   // For using strings
using namespace std;

struct Person {
    char name[50];  // Name of the person
    int age;        // Age of the person
};


int main() {
    // // 1. Writing to a file with truncation (default)
    // ofstream outFile1("example1.txt", ios::out);  // Open file for writing (default mode: truncation)
    // if (!outFile1) {
    //     cerr << "Error opening file for writing!" << endl;
    //     return 1;
    // }
    // outFile1 << "This is the first file (written with truncation).\n";
    // outFile1.close();

    // // 2. Writing to a file with append mode
    // ofstream outFile2("example2.txt", ios::out | ios::app);  // Open file for writing in append mode
    // if (!outFile2) {
    //     cerr << "Error opening file for appending!" << endl;
    //     return 1;
    // }
    // outFile2 << "This content is appended to the file.\n";
    // outFile2.close();

    // // 3. Reading from a file
    // ifstream inFile("example2.txt", ios::in);  // Open file for reading
    // if (!inFile) {
    //     cerr << "Error opening file for reading!" << endl;
    //     return 1;
    // }
    // string line;
    // while (getline(inFile, line)) {
    //     cout << line << endl;  // Output content from file
    // }
    // inFile.close();

    // // 4. Writing in binary mode
    // ofstream outBinaryFile("exampleBinary.dat", ios::out | ios::binary);  // Open file for binary writing
    // if (!outBinaryFile) {
    //     cerr << "Error opening file for binary writing!" << endl;
    //     return 1;
    // }
    // int number = 42;
    // outBinaryFile.write(reinterpret_cast<char*>(&number), sizeof(number));  // Write binary data
    // outBinaryFile.close();

    // // 5. Reading from a binary file
    // ifstream inBinaryFile("exampleBinary.dat", ios::in | ios::binary);  // Open file for binary reading
    // if (!inBinaryFile) {
    //     cerr << "Error opening binary file for reading!" << endl;
    //     return 1;
    // }
    // int readNumber;
    // inBinaryFile.read(reinterpret_cast<char*>(&readNumber), sizeof(readNumber));  // Read binary data
    // cout << "Read binary data: " << readNumber << endl;
    // inBinaryFile.close();

    /** TEXT FILES */
    // ofstream myfileV2 ("example.txt");  // Open or create "example.txt" for writing
    // if (myfileV2.is_open())  // Check if the file is successfully opened for writing
    // {
    //     myfileV2 << "This is a line.\n";  // Write a line to the file followed by a newline
    //     myfileV2 << "This is another line.\n";  // Write another line to the file followed by a newline
    //     myfileV2.close();  // Close the file after writing is done
    // }
    // else cout << "Unable to open file";  // If the file couldn't be opened, print an error message

    /** READING FILES */
    // string line;  // Declare a string variable to store each line read from the file
    // ifstream myfile ("example.txt");  // Open the file "example.txt" for reading
    // if (myfile.is_open())  // Check if the file is successfully opened for reading
    // {
    //     while (getline(myfile, line))  // Read each line from the file and store it in the variable 'line'
    //     {
    //         cout << line << '\n';  // Output the current line to the console
    //     }
    //     myfile.close();  // Close the file after reading is done
    // }
    // else cout << "Unable to open file";  // If the file couldn't be opened, print an error message

    /** CHECKING STATE FLAGS */
    // ifstream myfile("example.txt");

    // if (!myfile) {  // Check if the file could not be opened
    //     cerr << "Unable to open file\n";
    //     return 1;
    // }

    // string line;
    // // Read the file line by line
    // while (getline(myfile, line)) {
    //     cout << line << endl;

    //     // Check for any errors during reading
    //     if (myfile.fail()) {
    //         cerr << "Error reading the file\n";
    //         break;
    //     }

    //     // Check if we've reached the end of the file
    //     if (myfile.eof()) {
    //         cout << "End of file reached\n";
    //         break;
    //     }
    // }

    // // Check if a serious error occurred
    // if (myfile.bad()) {
    //     cerr << "A serious error occurred during file I/O\n";
    // }

    // myfile.close();  // Close the file

    /** GET AND PUT STREAM POSITIONING */
    // Open file for writing (overwrite mode)
    // ofstream outfile("example.txt");
    // if (!outfile) {
    //     cerr << "Unable to open file for writing\n";
    //     return 1;
    // }

    // // Write some text to the file
    // outfile << "Hello, world!\n";
    // outfile << "This is a test.\n";

    // // Get the current position of the put pointer
    // streampos pos = outfile.tellp();
    // cout << "Current put pointer position: " << pos << endl;

    // // Move the put pointer to the beginning of the file
    // outfile.seekp(0, ios::beg);

    // // Write at the beginning of the file (overwriting existing content)
    // outfile << "This text overwrites the first line.\n";
    // outfile.close();  // Close the output file stream

    // // Open file for reading
    // ifstream infile("example.txt");
    // if (!infile) {
    //     cerr << "Unable to open file for reading\n";
    //     return 1;
    // }

    // // Read and print the contents of the file
    // string line;
    // while (getline(infile, line)) {
    //     cout << line << endl;
    // }

    // // Get the current position of the get pointer (after reading the entire file)
    // streampos read_pos = infile.tellg();
    // cout << "Current get pointer position: " << read_pos << endl;

    // // Move the get pointer back to the beginning of the file
    // infile.seekg(0, ios::beg);

    // // Read and print the first line again after seeking back to the beginning
    // getline(infile, line);
    // cout << "First line after seeking: " << line << endl;

    // infile.close();  // Close the input file stream

    /** WORKING WITH BINARY FILES */

     // Create a Person object
    Person person1 = {"John Doe", 30};

    // Open the file for writing in binary mode
    ofstream outfile("person.dat", ios::binary);
    if (!outfile) {
        cerr << "Unable to open file for writing.\n";
        return 1;
    }

    // Write the Person object to the file
    outfile.write(reinterpret_cast<char*>(&person1), sizeof(person1));
    outfile.close();  // Close the file after writing

    // Create an empty Person object to read data into
    Person person2;

    // Open the file for reading in binary mode
    ifstream infile("person.dat", ios::binary);
    if (!infile) {
        cerr << "Unable to open file for reading.\n";
        return 1;
    }

    // Read the Person object from the file
    infile.read(reinterpret_cast<char*>(&person2), sizeof(person2));
    infile.close();  // Close the file after reading

    // Output the data read from the file
    cout << "Name: " << person2.name << "\n";
    cout << "Age: " << person2.age << "\n";
    return 0;
}
