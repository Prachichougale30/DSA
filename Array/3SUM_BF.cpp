#include<bits/stdc++.h>
using namespace std;

// brute force
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size(); 
        
        set<vector<int>> s; //set<uniqueTriplets>

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> trip={nums[i],nums[j],nums[k]};
                        sort(trip.begin(),trip.end());

                        if(s.find(trip)==s.end()){
                            s.insert(trip);
                        ans.push_back(trip);                        }
                    }
                }
            }

        }
        return ans;//TLE 

    }};
int main(){

}