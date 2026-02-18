#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        
        // Step 1: Count frequency
        for(char c : s) {
            mp[c]++;
        }
        
        // Step 2: Move to vector
        vector<pair<char,int>> vec(mp.begin(), mp.end());
        
        // Step 3: Sort by frequency descending
        sort(vec.begin(), vec.end(), [](pair<char,int>& a, pair<char,int>& b) {
            return a.second > b.second;
        });
        
        // Step 4: Build result
        string result = "";
        for(auto &p : vec) {
            result.append(p.second, p.first);
        }
        
        return result;
    }
};
