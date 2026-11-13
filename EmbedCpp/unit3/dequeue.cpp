#include <iostream>
#include <deque>    // Required header for deque

using namespace std;

int main() {
    deque<int> dq;

    // 1. Insertion at both ends
    dq.push_back(30);   // Adds to back: {30}
    dq.push_back(40);   // Adds to back: {30, 40}
    dq.push_front(20);  // Adds to front: {20, 30, 40}
    dq.push_front(10);  // Adds to front: {10, 20, 30, 40}

    cout << "Front element: " << dq.front() << endl;
    // Output: Front element: 10
    
    cout << "Back element: " << dq.back() << endl;
    // Output: Back element: 40


    // 2. Random Access (like a vector)
    cout << "Element at index 2: " << dq[2] << endl;
    // Output: Element at index 2: 30


    // 3. Deletion at both ends
    dq.pop_front(); // Removes 10 from front
    dq.pop_back();  // Removes 40 from back
    
    cout << "New size after pop_front and pop_back: " << dq.size() << endl;
    // Output: New size after pop_front and pop_back: 2

    return 0;
}