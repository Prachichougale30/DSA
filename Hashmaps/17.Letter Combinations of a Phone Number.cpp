#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<string> ans;
    
    void solve(int index, string digits, string temp, vector<string> &map){
        
        if(index == digits.size()){
            ans.push_back(temp);
            return;
        }
        
        string letters = map[digits[index] - '0'];
        
        for(char c : letters){
            solve(index + 1, digits, temp + c, map);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()) return {};
        
        vector<string> map = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        solve(0, digits, "", map);
        
        return ans;
    }
};