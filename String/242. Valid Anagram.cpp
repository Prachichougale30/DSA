#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool isAnagram(string s,string t){
        if(s.length()!=t.length()) return false;

        unordered_map<char,int> freq;

        for(char ch:s){
            freq[ch]++;
        }
        for(char ch:t){
            freq[ch]--;
        }
        for(auto it:freq){
            if(it.second!=0) return false;
        }
        return true;
    }

};