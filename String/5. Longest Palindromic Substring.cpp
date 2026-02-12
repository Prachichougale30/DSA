#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        
        int start = 0;
        int maxLen = 1;

        for(int i = 0; i < s.length(); i++) {
            // Odd length palindrome (center at i)
            int left = i, right = i;
            while(left >= 0 && right < s.length() && s[left] == s[right]) {
                if(right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }

            // Even length palindrome (center between i and i+1)
            left = i;
            right = i + 1;
            while(left >= 0 && right < s.length() && s[left] == s[right]) {
                if(right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};
