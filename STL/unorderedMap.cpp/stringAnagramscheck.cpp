#include<iostream>
#include <unordered_map>
using namespace std;

bool areAnagrams(string str1,string str2){
    if(str1.length()!=str2.length()){
        return false;
    }
    unordered_map<char,int> freq;

    for(char ch:str1){
        freq[ch]++;
    }
    
}