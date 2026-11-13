#include <iostream>
#include <vector>   // Required header for vector
#include <algorithm> // Required for sort, reverse, find

using namespace std;

int main() {
    // 1. Initialization and Element Insertion
    vector<int> vec; // Creates an empty vector of integers

    // push_back(): Adds elements to the end of the vector
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    
    // Output check: vec contains {10, 20, 30}
    cout << "Size after push_back: " << vec.size() << endl; 
    // Output: Size after push_back: 3


    // 2. Element Access
    cout << "Element at index 1: " << vec[1] << endl;        
    // Output: Element at index 1: 20

    cout << "Element using at(2): " << vec.at(2) << endl;     
    // Output: Element using at(2): 30

    cout << "First element (front): " << vec.front() << endl; 
    // Output: First element (front): 10

    cout << "Last element (back): " << vec.back() << endl;   
    // Output: Last element (back): 30


    // 3. Modifying the Vector (Insert and Erase)
    // insert(): Inserts an element at a specific iterator position
    // vec.begin() points to the first element. +1 means index 1.
    vec.insert(vec.begin() + 1, 15); 
    // Vector is now: {10, 15, 20, 30}

    cout << "After insert(15 at index 1), element at index 1: " << vec[1] << endl; 
    // Output: After insert(15 at index 1), element at index 1: 15

    // pop_back(): Removes the last element from the vector
    vec.pop_back(); 
    // Vector is now back to: {10, 15, 20}
    cout << "Back element after pop_back(): " << vec.back() << endl; 
    // Output: Back element after pop_back(): 20


    // 4. Capacity Functions
    cout << "Current size: " << vec.size() << endl;         
    // Output: Current size: 3
    
    cout << "Current capacity: " << vec.capacity() << endl; 
    // Output: Current capacity: (Usually 4 or higher, depending on memory allocation)

    vec.reserve(10); // Reserves memory for at least 10 elements
    cout << "Capacity after reserve(10): " << vec.capacity() << endl; 
    // Output: Capacity after reserve(10): 10


    // 5. Sorting and Reversing (using <algorithm>)
    vector<int> unsorted = {40, 10, 30, 20};
    
    // sort(): Sorts in ascending order
    sort(unsorted.begin(), unsorted.end());
    cout << "Sorted vector: ";
    for(int val : unsorted) cout << val << " ";
    cout << endl;
    // Output: Sorted vector: 10 20 30 40 

    // reverse(): Reverses the vector elements
    reverse(unsorted.begin(), unsorted.end());
    cout << "Reversed vector: ";
    for(int val : unsorted) cout << val << " ";
    cout << endl;
    // Output: Reversed vector: 40 30 20 10 


    // 6. Clearing the Vector
    vec.clear(); // Removes all elements, size becomes 0
    cout << "Is vector empty after clear()? " << (vec.empty() ? "Yes" : "No") << endl;
    // Output: Is vector empty after clear()? Yes

    return 0;
}