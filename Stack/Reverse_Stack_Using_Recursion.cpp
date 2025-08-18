// User function Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Recursive helper function to insert x at the bottom of stack
    void solve(stack<int> &s, int x) {
        if (s.empty()) {
            s.push(x); // Base case: insert x when stack is empty
            return;
        }

        int num = s.top(); // Store the top element
        s.pop();           // Remove top element

        solve(s, x);       // Recursive call

        s.push(num);       // Push stored elements back after inserting x at bottom
    }

    // Main function to call solve and return updated stack
    stack<int> insertAtBottom(stack<int> st, int x) {
        solve(st, x);
        return st;
    }
};

// -------- Main function to test --------
int main() {
    Solution obj;

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4); // Top of stack is 4

    int x = 0; // Element to insert at bottom

    cout << "Original Stack (Top to Bottom): 4 3 2 1\n";

    // Call insertAtBottom to insert x at the bottom
    stack<int> updatedStack = obj.insertAtBottom(st, x);

    // Print updated stack (Top to Bottom)
    cout << "Updated Stack (Top to Bottom): ";
    while (!updatedStack.empty()) {
        cout << updatedStack.top() << " ";
        updatedStack.pop();
    }
    cout << endl;

    return 0;
}
