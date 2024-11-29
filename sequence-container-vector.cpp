#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void printV(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

   // Creating an empty vector
    // vector<int> v1;

    // Creating a vector of 5 elements from
    // initializer list
    // vector<int> v2 = {1, 4, 2, 3, 5};

    // Creating a vector of 5 elements with
    // default value
    // vector<int> v3(5, 9);

    // printV(v1);
    // printV(v2);
    // printV(v3);

    vector<char> v = {'a', 'c', 'f', 'd', 'z'};

    // Accessing and printing values using indexes
    // cout << v[3] << endl;
    // cout << v.at(2) << endl;

    // Updating values using indexes 3 and 2
    // v[3] = 'D';
    // v.at(2) = 'F';
    
    // cout << v[3] << endl;
    // cout << v.at(2) << endl;

    // Traversing vector using vector size()
    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i] << " ";
    // }

    // vector<char> v1 = {'a', 'f', 'd'};
    // Inserting 'z' at the back
    // v1.push_back('z');

    // Inserting 'c' at index 1
    // v1.insert(v1.begin() + 1, 'c');

    // for (int i = 0; i < v1.size(); i++) {
    //     cout << v[i] << " ";
    // }

    // Deleting last element 'z'
    v.pop_back();
      for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
  
      // Deleting element 'f'
    v.erase(find(v.begin(), v.end(), 'f'));
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}