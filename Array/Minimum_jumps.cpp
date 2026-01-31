#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n=arr.size();
        int max=0;
        int maxRange=0;
        int jumps=0;
        
        if(arr[0]==0) return -1;
        for(int i=0;i<n;i++){
            max=std::max(max,i+arr[i]);
            
            if(maxRange==i){
                maxRange=max;
                jumps++;
                if(maxRange>=n-1)
                {
                    return jumps;
                }
            }
        }
        return -1;
    }
};
