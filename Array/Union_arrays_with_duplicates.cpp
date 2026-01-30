#include <bits/stdc++.h>
using namespace std;

vector<int> unionOfArrays(vector<int>& a, vector<int>& b) {
    unordered_set<int> st;

    // Insert elements of first array
    for (int x : a) {
        st.insert(x);
    }

    // Insert elements of second array
    for (int x : b) {
        st.insert(x);
    }

    // Convert set to vector
    vector<int> result(st.begin(), st.end());

    return result;
}
