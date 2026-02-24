#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
    int removeDuplicate(vector<int>&arr){
        int k=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]!=arr[i-1]){
                arr[k]=arr[i];
                k++;
            }
        }
        return k;
    }

};