#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Insertion at both ends
    dq.push_back(30);  // {30}
    dq.push_back(40);  // {30, 40}
    dq.push_front(20); // {20, 30, 40}
    dq.push_front(10); // {10, 20, 30, 40}

    cout << "Deque elements after insertions: ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    // Deletion at both ends
    dq.pop_front(); // Removes 10
    dq.pop_back();  // Removes 40

    cout << "Deque elements after pop_front and pop_back: ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    return 0;
}