#include <iostream>
#include <map>      // Required header for map
#include <string>

using namespace std;

int main() {
    // 1. Initialization and Insertion
    map<int, string> studentMap;

    // Method 1: Using array subscript operator []
    studentMap[101] = "Alice";
    studentMap[103] = "Charlie";

    // Method 2: Using insert() with make_pair
    studentMap.insert(make_pair(102, "Bob"));

    // Map automatically sorts by key: {101: Alice, 102: Bob, 103: Charlie}
    cout << "Size of map: " << studentMap.size() << endl;
    // Output: Size of map: 3


    // 2. Element Access
    cout << "Student with ID 102: " << studentMap[102] << endl;
    // Output: Student with ID 102: Bob

    // at() throws an error if key doesn't exist (unlike [])
    cout << "Student with ID 101 using at(): " << studentMap.at(101) << endl;
    // Output: Student with ID 101 using at(): Alice


    // 3. Searching for a Key (find())
    auto it = studentMap.find(103);
    if (it != studentMap.end()) {
        cout << "Found ID 103 with name: " << it->second << endl;
    }
    // Output: Found ID 103 with name: Charlie


    // 4. Deletion (erase())
    studentMap.erase(101); // Removes key 101 and its value
    cout << "Size after erasing ID 101: " << studentMap.size() << endl;
    // Output: Size after erasing ID 101: 2

    return 0;
}