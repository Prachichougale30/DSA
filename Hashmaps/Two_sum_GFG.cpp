#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        
        unordered_map<int,int> m;
        
        for(int i = 0; i < arr.size(); i++){
            
            int r = target - arr[i];
            
            if(m.count(r)){
                return true;
            }
            
            m[arr[i]] = i;
        }
        
        return false;
    }
};