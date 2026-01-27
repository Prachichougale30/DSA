#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex; // store last seen index
        int n = s.size();
        int maxLen = 0, start = 0;

        for (int i = 0; i < n; i++) {
            // If char already seen in current window
            if (lastIndex.find(s[i]) != lastIndex.end() && lastIndex[s[i]] >= start) {
                start = lastIndex[s[i]] + 1; // move start forward
            }

            lastIndex[s[i]] = i; // update index
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
    
};