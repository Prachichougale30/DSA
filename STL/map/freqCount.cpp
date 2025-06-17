#include<iostream>
#include<map>
using namespace std;
int  main(){
    int arr[]={1,2,1,2,23,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    map<int,int> m;
    for(int i=0;i<n;i++){
       ++m[arr[i]];
    }

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
}
