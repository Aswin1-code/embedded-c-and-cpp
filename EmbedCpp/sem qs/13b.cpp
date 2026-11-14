#include <iostream>
#include <set>      // Required for std::set
#include <algorithm> // Required for std::find

using namespace std;

int main() {
    cout << "=== Searching in a Set Using Iterators ===" << endl;

    // 1. Initialize a set of integer values (sets are automatically sorted and unique)
    set<int> sensorIDs = {105, 101, 108, 102, 110};

    // Displaying the set elements using an iterator
    cout << "Available Sensor IDs in set: ";
    for (auto it = sensorIDs.begin(); it != sensorIDs.end(); ++it) {
        cout << *it << " "; // Dereferencing iterator to get the value
    }
    cout << endl;

    // Element we want to search for
    int targetID = 108;

    // ==========================================
    // Method 1: Using the set's built-in .find() member function (Recommended for Sets)
    // ==========================================
    // .find() returns an iterator to the element if found, or set::end() if not found.
    set<int>::iterator it1 = sensorIDs.find(targetID);

    cout << "\n[Method 1] Using set::find():" << endl;
    if (it1 != sensorIDs.end()) {
        cout << "Success! Sensor ID " << targetID << " found in the set." << endl;
        cout << "Value pointed by iterator: " << *it1 << endl;
    } else {
        cout << "Sensor ID " << targetID << " not found." << endl;
    }


    // ==========================================
    // Method 2: Using the generic <algorithm> std::find() with iterators
    // ==========================================
    // std::find takes the starting iterator, ending iterator, and the target value.
    auto it2 = find(sensorIDs.begin(), sensorIDs.end(), targetID);

    cout << "\n[Method 2] Using std::find() algorithm:" << endl;
    if (it2 != sensorIDs.end()) {
        cout << "Success! Element " << *it2 << " located using generic iterator search." << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}