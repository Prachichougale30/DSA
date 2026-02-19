#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
int countMinReversals(string s){
 int len=s.length();
        
        if(len%2!=0){
            return -1;
        }
        stack<char> st;
        for(int i=0;i<len;i++){
            if(s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(!st.empty()&& st.top()=='{'){
                    st.pop();
                }
                else{
                    st.push(s[i]);   
                }
            }
        }
        
        int m=0,n=0;
        
        while(!st.empty()){
            if(st.top()=='{'){
                m++;
            }
            else{
                n++;
            }
            st.pop();
        }
        
        return ((m+1)/2+(n+1)/2);
} 
};