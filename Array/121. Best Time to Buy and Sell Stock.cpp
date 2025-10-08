#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
            int mini=prices[0],profit=0;
            for(int sell=0;sell<prices.size();sell++){
                if(mini>prices[sell]){
                    mini=prices[sell];
                }
                else if(prices[sell]-mini>profit){
                     profit=prices[sell]-mini;

                }
            }
                 return profit;
        }
    };