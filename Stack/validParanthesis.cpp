#include <bits/stdc++.h>
using namespace std;
/*
Problem statement
You're given a string 'S' consisting of "{", "}", "(", ")", "[" and "]" .
Return true if the given string 'S' is balanced, else return false.
*/
bool isValidParanthesis(string expression)
{
    stack<char> s;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            // Closing bracket
            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false; // Stack empty but closing bracket found
            }
        }
    }

    return s.empty(); // True if all brackets matched
}
int main()
{
    string exp1 = "{[()]}";
    string exp2 = "{[(])}";

    cout << isValidParanthesis(exp1) << endl; // 1 (true)
    cout << isValidParanthesis(exp2) << endl; // 0 (false)

    return 0;
}
