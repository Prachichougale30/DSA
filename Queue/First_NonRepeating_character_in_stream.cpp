#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string FirstNonRepeating(string &s) {
        unordered_map<char,int> count;
        queue<char> q;   // better to use char
        string ans="";
        
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            
            // increase count
            count[ch]++;
            
            // push to queue
            q.push(ch);
            
            // remove from front until non-repeating found
            while(!q.empty() && count[q.front()] > 1){
                q.pop();
            }
            
            if(q.empty()){
                ans.push_back('#');   // no non-repeating
            }
            else{
                ans.push_back(q.front());
            }
        }
        
        return ans;   // ✅ you forgot this
    }
};
