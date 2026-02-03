#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int positiveIndx=0,negativeIdx=1;

        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[negativeIdx]=nums[i];
                negativeIdx+=2;
            }
            else{
                ans[positiveIndx]=nums[i];
                positiveIndx+=2;
            }
        }
        return ans;
    }
};