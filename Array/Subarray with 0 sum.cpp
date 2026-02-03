#include<bits/stdc++.h>
using namespace std;

bool subArrayExists(vector<int>& arr) {
    unordered_set<int> s;
    int sum = 0;

    for (int x : arr) {
        sum += x;

        // Case 1: prefix sum is 0
        if (sum == 0)
            return true;

        // Case 2: prefix sum already seen
        if (s.find(sum) != s.end())
            return true;

        s.insert(sum);
    }
    return false;
}
