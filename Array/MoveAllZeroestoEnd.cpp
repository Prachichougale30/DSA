#include<bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int nonZeroindex=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0){
                swap(arr[nonZeroindex],arr[i]);
                nonZeroindex++;
            }
        }
    }
};