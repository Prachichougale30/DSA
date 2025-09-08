#include <bits/stdc++.h>
using namespace std;
/*Problem statement
You are given a stack ‘S’. Your task is to sort the stack recursively.
Looping through the stack is not allowed.
You need to return a stack that is sorted in descending order.
*/
void sortedInsert(stack<int> &st, int num)
{
    if (st.empty() || (!st.empty() && st.top() < num))
    {
        st.push(num);
        return;
    }
    int n = st.top();
    st.pop();

    sortedInsert(st, num);

    st.push(n);
}

stack<int> sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return s;
    }

    int num = s.top();
    s.pop();

    sortStack(s);

    sortedInsert(s, num);

    return s;
}