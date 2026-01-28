#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int>& arr, long long target) {
    int n = arr.size();
    int left = 0;
    long long currentSum = 0;

    for (int right = 0; right < n; right++) {
        currentSum += arr[right];

        while (currentSum > target && left <= right) {
            currentSum -= arr[left];
            left++;
        }

        if (currentSum == target) {
            return {left + 1, right + 1}; // 1-based indexing
        }
    }

    return {-1};
}
