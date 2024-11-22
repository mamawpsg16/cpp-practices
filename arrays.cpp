#include <iostream>
#include <array>
using namespace std;

void printArray(int arr[], int size) {
    // arr is treated as a pointer to the first element
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    // int foo [5] = {1, 2, 3, 4, 5};
    // int foo [] = {1, 2, 3, 4, 5};
    // int n, result=0;
    /** ACCESSING VALUE OF ARRAY */
    // cout << "foo[2] old value : " << foo[2] <<endl;
    // foo[2] = 6;
    // cout << "foo[2] new value : " << foo[2] <<endl;
    // int x = foo[2];
    // cout << "value of x = foo[2]: " << x <<endl;

    // for ( n=0 ; n<5 ; ++n )
    // {
    //     result += foo[n];
    // }
    // cout << "Result = " << result <<endl;

    /** MULTIDIMENSIONAL ARRAY */
    // int arr[3][4] = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12}
    // };

    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    /** ARRAY AS PARAMETERS */
    // int numbers[] = {1, 2, 3, 4, 5};
    // cout << sizeof(numbers)<< " "  << sizeof(numbers[0]) << endl;
    // int size = sizeof(numbers) / sizeof(numbers[0]); // Calculate array size
    // printArray(numbers, size); // 'numbers' is automatically passed as a pointer

    /** LIBRARY ARRAYS */
    std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << arr.size();
     // Print each element of the array
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }

    return 0; 
}