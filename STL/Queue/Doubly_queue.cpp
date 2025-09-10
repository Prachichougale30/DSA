#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> q;
    q.push_front(12);
    q.push_back(14);
    
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;

    q.pop_front();

    cout<<q.front()<<endl;
    cout<<q.back();
    q.pop_back();

    if(q.empty()){
        cout<<" Q IS EMPTY"<<endl;
    }
    else{
        cout<<"q is not emty"<<endl;
    }
}