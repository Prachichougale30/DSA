#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        vector<int>sumStore;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                sumStore.push_back(sum);
            }
            
        }
        
        sort(sumStore.begin(),sumStore.end());
        return sumStore[sumStore.size()-k];
        }
};