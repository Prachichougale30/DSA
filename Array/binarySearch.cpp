// Given a sorted array arr and an integer k, find the position(0-based indexing) at which k is present in the array using binary search.

// Note: If multiple occurrences are there, please return the smallest index.

// Input: arr[] = [1, 1, 1, 1, 2], k = 1
// Output: 0
// Explanation: 1 appears at index 0.
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
     auto lower=lower_bound(arr.begin(),arr.end(),k);
     int index= lower - arr.begin();
     if(arr[index] != k)return -1;
     return index;
    }
};