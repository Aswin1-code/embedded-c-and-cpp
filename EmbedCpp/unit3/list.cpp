#include <iostream>
#include <list>     // Required header for list
#include <algorithm> // Required for remove, sort, etc.

using namespace std;

int main() {
    // 1. Initialization and Insertion
    list<int> myList; // Creates an empty doubly linked list

    // push_back(): Adds elements to the back (tail)
    myList.push_back(30);
    myList.push_back(40);

    // push_front(): Adds elements to the front (head) - (Vectors don't have this!)
    myList.push_front(20);
    myList.push_front(10);
    
    // List is now: {10, 20, 30, 40}
    cout << "Size of list: " << myList.size() << endl; 
    // Output: Size of list: 4


    // 2. Element Access (Front and Back only - No random access like myList[2])
    cout << "Front element: " << myList.front() << endl; 
    // Output: Front element: 10

    cout << "Back element: " << myList.back() << endl;   
    // Output: Back element: 40


    // 3. Modifying the List (Insert and Erase anywhere in O(1) time)
    // To insert/erase in the middle, we use iterators (since list has no index operator)
    auto it = myList.begin(); // Iterator points to the first element (10)
    advance(it, 2);           // Move iterator forward by 2 positions (now points to 30)

    // insert(): Inserts 25 before 30
    myList.insert(it, 25);
    // List is now: {10, 20, 25, 30, 40}

    cout << "Element after insertion at iterator position: " << *it << endl;
    // Output: Element after insertion at iterator position: 30 (iterator still points to 30)


    // 4. Removal Functions
    myList.pop_front(); // Removes the first element (10)
    // List is now: {20, 25, 30, 40}
    cout << "New front element after pop_front(): " << myList.front() << endl;
    // Output: New front element after pop_front(): 20

    myList.pop_back();  // Removes the last element (40)
    // List is now: {20, 25, 30}

    // remove(): Removes all elements matching a specific value without needing an iterator
    myList.push_back(25); // List is now {20, 25, 30, 25}
    myList.remove(25);    // Removes ALL instances of 25
    // List is now: {20, 30}


    // 5. Specialized List Member Functions (Faster than generic algorithms)
    list<int> l = {40, 10, 30, 20, 10};
    
    // sort(): Lists have their own built-in sort member function
    l.sort(); 
    // List is now: {10, 10, 20, 30, 40}
    
    // unique(): Removes consecutive duplicate elements
    l.unique(); 
    // List is now: {10, 20, 30, 40}
    cout << "List after sort() and unique(): ";
    for(int val : l) cout << val << " ";
    cout << endl;
    // Output: List after sort() and unique(): 10 20 30 40 

    // reverse(): Reverses the linked list
    l.reverse();
    cout << "Reversed list: ";
    for(int val : l) cout << val << " ";
    cout << endl;
    // Output: Reversed list: 40 30 20 10 


    // 6. Clear
    myList.clear();
    cout << "Is list empty? " << (myList.empty() ? "Yes" : "No") << endl;
    // Output: Is list empty? Yes

    return 0;
}