#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<int> s;   // main stack (stores elements and encoded values)
    int mini;       // keeps track of the current minimum

public:
    // Insert element
    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
        } else {
            if (data < mini) {
                // encode new minimum
                int val = 2 * data - mini;
                s.push(val);
                mini = data;
            } else {
                s.push(data);
            }
        }
    }

    // Remove element
    void pop() {
        if (s.empty()) {
            cout << "Stack is empty! Cannot pop.\n";
            return;
        }

        int curr = s.top();
        s.pop();

        if (curr < mini) {
            // restore previous minimum
            mini = 2 * mini - curr;
        }
    }

    // Return top element
    int top() {
        if (s.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }

        int curr = s.top();
        if (curr < mini) {
            return mini;   // return actual element (not encoded)
        } else {
            return curr;
        }
    }

    // Return current minimum
    int getMin() {
        if (s.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return mini;
    }

    // Check if empty
    bool empty() {
        return s.empty();
    }
};

int main() {
    SpecialStack st;

    cout << "Pushing 5\n";
    st.push(5);
    cout << "Top: " << st.top() << " | Min: " << st.getMin() << "\n\n";

    cout << "Pushing 3\n";
    st.push(3);
    cout << "Top: " << st.top() << " | Min: " << st.getMin() << "\n\n";

    cout << "Pushing 7\n";
    st.push(7);
    cout << "Top: " << st.top() << " | Min: " << st.getMin() << "\n\n";

    cout << "Popping\n";
    st.pop();
    cout << "Top: " << st.top() << " | Min: " << st.getMin() << "\n\n";

    cout << "Popping\n";
    st.pop();
    cout << "Top: " << st.top() << " | Min: " << st.getMin() << "\n\n";

    cout << "Popping\n";
    st.pop();
    if (st.empty()) {
        cout << "Stack is now empty!\n";
    }

    return 0;
}
