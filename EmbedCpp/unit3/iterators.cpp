//1. Traversing and Printing a Container
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};

    // Formal iterator syntax
    cout << "Elements: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    // Output: Elements: 10 20 30 40
    return 0;
}
//=============================================================================
//2. Modifying Elements During Iteration
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = {1, 2, 3};

    // Using 'auto' iterator to double each element's value
    for (auto it = l.begin(); it != l.end(); ++it) {
        *it = *it * 2; // Dereference and modify value
    }

    cout << "Modified list: ";
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    // Output: Modified list: 2 4 6
    return 0;
}
//=============================================================================
//3. Inserting or Erasing Elements at a Specific Position
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 30, 40};

    // Create an iterator pointing to the second position (index 1, value 30)
    auto it = v.begin() + 1; 

    // Insert 20 right before 30
    v.insert(it, 20);
    // Vector is now: {10, 20, 30, 40}

    cout << "After insertion: ";
    for (auto x : v) cout << x << " ";
    // Output: After insertion: 10 20 30 40 
    return 0;
}
//=============================================================================


//=============================================================================