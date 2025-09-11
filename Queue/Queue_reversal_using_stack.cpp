#include<bits/stdc++.h>
using namespace std;

// function Template for C++

class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        // code here.
        stack<int> s;
        while(!q.empty()){
            int element=q.front();
            q.pop();
            s.push(element);
        }
        while(!s.empty()){
            int element=s.top();
            s.pop();
            q.push(element);
            
        }
        return q;
        
    }
};