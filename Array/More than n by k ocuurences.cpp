#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(vector<int>& arr, int k) {
        // Your code here
        unordered_map<int,int> freq;
        int n=arr.size();
        int x=n/k;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        
        int count=0;
        for(auto i:freq){
            if(i.second>x){
               count++;
            }
        }
        return count;
    }
};