#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int size=s.size();
        int balance=0;

        string result;
        for(char c:s){
            if(c=='('){
                if(balance>0) result+=c;
                balance++;
            }
            else{
                balance--;
                if(balance>0)result+=c;
            }
        }
        return result;

    }
};