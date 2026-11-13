#include <iostream>
#include <queue>    // Required header for queue

using namespace std;

int main() {
    queue<int> q;

    // 1. Insertion (push()) - adds to the back of the line
    q.push(10);
    q.push(20);
    q.push(30); // 30 is at the back, 10 is at the front

    cout << "Queue size: " << q.size() << endl;
    // Output: Queue size: 3


    // 2. Accessing front and back elements
    cout << "Front element (next to be served): " << q.front() << endl;
    // Output: Front element (next to be served): 10

    cout << "Back element (last in line): " << q.back() << endl;
    // Output: Back element (last in line): 30


    // 3. Removal (pop() removes from the front)
    q.pop(); // Removes 10

    cout << "New front element after pop(): " << q.front() << endl;
    // Output: New front element after pop(): 20

    return 0;
}