#include <iostream>
#include <cstring>
using namespace std;

// 1. Generic Function Template
template <typename T>
void compare(T a, T b) {
    if (a > b) cout << a << " is greater.\n";
    else cout << b << " is greater or equal.\n";
}

// 2. Full Template Specialization for C-style strings (const char*) comparing lengths
template <>
void compare<const char*>(const char* a, const char* b) {
    cout << "[Specialized String Length Comparison] ";
    if (strlen(a) > strlen(b)) cout << a << " is longer.\n";
    else cout << b << " is longer or equal in length.\n";
}

int main() {
    compare(10, 25);              // Uses generic template for integers
    compare(5.5, 3.2);            // Uses generic template for floats
    compare("Apple", "Pineapple");// Uses specialized template for C-strings (compares lengths)
    return 0;
}