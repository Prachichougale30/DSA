#include <iostream>
#include <unordered_map>
using namespace std;
int main(){

    string name="Prachi";
    unordered_map<char,int> frq;

    for(char ch:name){
       frq[ch]++;
    }
    for(auto pair:frq){
        cout<<pair.first<<"->"<<pair.second<<endl;
    }
}