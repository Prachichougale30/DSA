#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
   void rev(vector<int>& arr, int start,int end){
       while(start<=end){
           swap(arr[start++],arr[end--]);
       }
   }

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
        d=d%n;
       if(d==0 || n<=1){
           return;
       }
       rev(arr,0,d-1);
       rev(arr,d,n-1);
       rev(arr,0,n-1);
    }
};