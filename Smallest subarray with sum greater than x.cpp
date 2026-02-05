#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int minLen = INT_MAX;
        int sum = 0;
        int start = 0;

        for (int end = 0; end < n; end++) {
            sum += arr[end];

            while (sum > x) {
                minLen = min(minLen, end - start + 1);
                sum -= arr[start];
                start++;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};