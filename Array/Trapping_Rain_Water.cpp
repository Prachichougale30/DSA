#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        if (n < 3) return 0;

        int left=0,right=n-1,leftMax=0,rightMax=0,water=0;
        
        while(left<right){
              if (arr[left] <= arr[right]){
            
                if(arr[left]>leftMax) {
            
                leftMax=arr[left];
    
            }else{
                water+=leftMax-arr[left];
            }
            left++;
              }
              
              else{
                  
                  if(arr[right]>=rightMax){
                      rightMax = arr[right];
                  }
                   else {
                       water+=rightMax-arr[right];
                   }
                   right--;
              }
          
        }
        return water;
    }
};