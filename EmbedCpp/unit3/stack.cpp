#include <iostream>
#include <stack>    // Required header for stack

using namespace std;

int main() {
    stack<int> st;

    // 1. Insertion (push())
    st.push(10);
    st.push(20);
    st.push(30); // 30 is now at the top of the stack

    cout << "Stack size: " << st.size() << endl;
    // Output: Stack size: 3


    // 2. Accessing the top element (top())
    cout << "Top element: " << st.top() << endl;
    // Output: Top element: 30


    // 3. Removal (pop() removes the top element, returns void)
    st.pop(); // Removes 30
    
    cout << "New top element after pop(): " << st.top() << endl;
    // Output: New top element after pop(): 20

    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;
    // Output: Is stack empty? No

    return 0;
}