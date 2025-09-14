#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int deficit = 0;   // total petrol shortage
        int balance = 0;   // current petrol balance
        int start = 0;     // potential start index
        
        for(int i = 0; i < n; i++) {
            balance += gas[i] - cost[i];
            
            // If balance goes negative, cannot reach next station
            if(balance < 0) {
                deficit += balance;   // add shortage
                start = i + 1;        // next station as new start
                balance = 0;          // reset balance
            }
        }
        
        // If total petrol >= total cost, return start
        if(balance + deficit >= 0) {
            return start;
        }
        return -1;
    }
};
