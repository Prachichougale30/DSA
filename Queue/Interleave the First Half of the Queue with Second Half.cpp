#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n=q.size();
        int half=n/2;
          queue<int> firstHalf;
        
        
        for(int i=0;i<half;i++){
            firstHalf.push(q.front());
            q.pop();
        }
        
        while(!firstHalf.empty()){
            q.push(firstHalf.front());
            firstHalf.pop();
            
            q.push(q.front());
            q.pop();
        }
    }
};