#include <bits/stdc++.h> 
using namespace std;
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*') {
            st.push(ch);
        }
        else {
            if (ch == ')') {
                bool isRedundant = true;

                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }

                // Pop the opening bracket '('
                if (!st.empty()) {
                    st.pop();
                }

                // If no operator was found between brackets
                if (isRedundant) {
                    return true;
                }
            }
        }
    }

    // No redundant brackets found
    return false;
}
