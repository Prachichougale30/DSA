#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSubsequence(vector<int>& arr) {
    if (arr.empty()) return 0;

    unordered_set<int> s;
    for (int x : arr)
        s.insert(x);

    int longest = 0;

    for (int x : arr) {
        // Check if x is the start of a sequence
        if (s.find(x - 1) == s.end()) {
            int current = x;
            int count = 1;

            // Count consecutive numbers
            while (s.find(current + 1) != s.end()) {
                current++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}

int main() {
    vector<int> arr1 = {2, 6, 1, 9, 4, 5, 3};
    vector<int> arr2 = {1, 9, 3, 10, 4, 20, 2};
    vector<int> arr3 = {15, 13, 12, 14, 11, 10, 9};

    cout << longestConsecutiveSubsequence(arr1) << endl; // 6
    cout << longestConsecutiveSubsequence(arr2) << endl; // 4
    cout << longestConsecutiveSubsequence(arr3) << endl; // 7

    return 0;
}
