#include<bits/stdc++.h>
using namespace std; 
class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int ans=INT_MAX;
        sort(a.begin(),a.end());
        
        int n=a.size();
        for(int i=0;i<n-m+1;i++){
            ans=min(ans,a[i+m-1]-a[i]);
            
        }
        return ans;
    }
};