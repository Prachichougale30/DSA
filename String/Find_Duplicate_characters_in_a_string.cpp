#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printDuplicates(string s) {
        map<char,int> mp;
        for(char c : s) mp[c]++;

        for(auto it : mp){
            if(it.second > 1){
                cout << it.first << " ";
            }
        }
    }
};

int main() {
    Solution obj;
    string s = "programming";
    obj.printDuplicates(s);
    return 0;
}
