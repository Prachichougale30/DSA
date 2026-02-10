#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isPalindrome(string& s) {
        // code here
       string rev=s;
       reverse(rev.begin(),rev.end());
        
        if(s==rev){
            return true;
        }
        else{
       return false;
            
        }
    }
};