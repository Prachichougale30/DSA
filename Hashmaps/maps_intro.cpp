#include<bits/stdc++.h>
using namespace std;

int main(){
    // cretaion
  map<string,int>m;

    // insertion
// Inserting Elements (3 Methods)
    // 1
    pair<string,int>p=make_pair("Babbar",3);
    m.insert(p);

    // 2
    pair<string,int>pair2("love",2);
    m.insert(pair2);
    
    // 3
    m["mera"]=1;

    m["mera"]=2;

    cout<<m["mera"]<<endl;
    cout<<m.at("Babbar")<<endl;
    cout<<m["UnknownKey"]<<endl;
    cout<<m.at("UnknownKey")<<endl;

    // size
    cout<<m.size()<<endl;

    // to check presenc
    cout<<m.count("bro")<<endl;
    cout<<m.count("love")<<endl;

    m.erase("love");
    cout<<m.size()<<endl;

    //
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"Iterator method"<<endl;
   map<string,int>::iterator it=m.begin();

    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    return 0;
}