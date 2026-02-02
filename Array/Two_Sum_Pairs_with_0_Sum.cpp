#include <bits/stdc++.h>
using namespace std;
// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        vector<vector<int>> result;
        int n= arr.size()-1;
        int left=0,right=n;      sort(arr.begin(), arr.end());
        
        while(left<right){
            int sum=arr[left]+arr[right];
            if(sum==0){
                result.push_back({arr[left],arr[right]});
            
            int x=arr[left],y=arr[right];
            
            while(left<right && arr[left]==x) left++;
            
            while(left<right && arr[right]==y) right--;
            }
            
              else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
            
        }
        return result;
        
    }
};