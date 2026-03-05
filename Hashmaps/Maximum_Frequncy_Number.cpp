#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxFrequency(int arr[], int n, int k) {
        
        unordered_map<int,int> count;
        int maxFreq = 0;
        int maxAns = 0;

        // count frequency
        for(int i = 0; i < n; i++){
            count[arr[i]]++;
            maxFreq = max(maxFreq, count[arr[i]]);
        }

        // find element with max frequency
        for(int i = 0; i < n; i++){
            if(maxFreq == count[arr[i]]){
                maxAns = arr[i];
                break;
            }
        }

        return maxAns;
    }
};