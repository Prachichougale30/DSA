#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    int bits=0;
    int temp=N;

    while (temp>0)
    {
        bits++;
        temp>>=1;
    }

    int mask=(1<<bits)-1;

    int result=N^mask;

    cout<<result<<endl;
    
}