#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};

    // 1. begin() and end() - Forward Traversal
    cout << "Forward (begin to end): ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 2. rbegin() and rend() - Reverse Traversal
    cout << "Reverse (rbegin to rend): ";
    for (auto rit = v.rbegin(); rit != v.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    return 0;
}