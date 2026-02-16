#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubStr(string S) {
        int count0 = 0, count1 = 0;
        int ans = 0;

        for(int i = 0; i < S.length(); i++) {
            if(S[i] == '0')
                count0++;
            else
                count1++;

            if(count0 == count1) {
                ans++;
                count0 = 0;
                count1 = 0;
            }
        }

        // If at the end counts are not zero,
        // it means total 0s and 1s are not equal
        if(count0 != 0 || count1 != 0)
            return -1;

        return ans;
    }
};
