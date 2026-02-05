#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        int n=arr.size();
        int currSum=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;i++)
        {
            int left=i+1;
            int right=n-1;
            
            while(left<right){
                currSum=arr[i]+arr[left]+arr[right];
                
                if(currSum==target) return true;
                else if(currSum<target) {
                    left++;
                }
                else if(currSum>target){
                    right--;
                }
            }
        }
        return false;
    }
};