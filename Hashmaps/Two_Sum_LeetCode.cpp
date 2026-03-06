#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int> m;
        vector<int> ans;
        for(int i=0;i<numbers.size();i++){
            int r=target-numbers[i];
            if(m.count(r)){
                ans.push_back(i);
                ans.push_back(m[r]);
                break;
            }
             m.insert({numbers[i],i});
        }
        return ans;
    }
};