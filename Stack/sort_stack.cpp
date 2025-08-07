#include <bits/stdc++.h> 
using namespace std;
void sortedInsert(stack<int>& st, int num) {
    if (st.empty() || (!st.empty() &&st.top() < num)) {
        st.push(num);
        return;
    }
    int n = st.top();
    st.pop();

    sortedInsert(st, num);

    st.push(n);
}

stack<int> sortStack(stack<int>& s) {
    if (s.empty()) {
		return s;}

    int num = s.top();
    s.pop();

    sortStack(s);

    sortedInsert(s, num);

    return s;
}