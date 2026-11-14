#include <iostream>
#include <string>

using namespace std;

// 1. Defining a Function Template
// 'typename T' (or 'class T') acts as a placeholder for any data type
template <typename T>
T findMax(T a, T b) {
    // If 'a' is greater than 'b', return 'a', otherwise return 'b'
    return (a > b) ? a : b;
}

int main() {
    cout << "=== Function Template: findMax() Demo ===" << endl;

    // 1. Calling findMax with Integers
    int int1 = 15, int2 = 25;
    cout << "Max of " << int1 << " and " << int2 << " is: " 
         << findMax(int1, int2) << endl;
    // Output: Max of 15 and 25 is: 25


    // 2. Calling findMax with Floats / Doubles
    double dbl1 = 45.89, dbl2 = 12.34;
    cout << "Max of " << dbl1 << " and " << dbl2 << " is: " 
         << findMax(dbl1, dbl2) << endl;
    // Output: Max of 45.89 and 12.34 is: 45.89


    // 3. Calling findMax with Characters (compares ASCII values)
    char char1 = 'A', char2 = 'Z';
    cout << "Max of '" << char1 << "' and '" << char2 << "' is: '" 
         << findMax(char1, char2) << "'" << endl;
    // Output: Max of 'A' and 'Z' is: 'Z'


    // 4. Calling findMax with Strings (compares alphabetically)
    string str1 = "Apple", str2 = "Zebra";
    cout << "Max of \"" << str1 << "\" and \"" << str2 << "\" is: \"" 
         << findMax(str1, str2) << "\"" << endl;
    // Output: Max of "Apple" and "Zebra" is: "Zebra"

    return 0;
}