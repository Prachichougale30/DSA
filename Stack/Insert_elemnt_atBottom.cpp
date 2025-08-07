#include<iostream>
#include<stack>
using namespace std;
class Solution {
  public:
void solve(stack<int>&s,int n){
    if(s.empty()){
        s.push(n);
        return;
    }
    int num=s.top();
    s.pop();

    solve(s,n);
    s.push(num);
}
stack<int> insertAtBottom(stack<int>&s,int n){
    solve(s,n);
    return s;
}
};