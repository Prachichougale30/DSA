#include<iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> studentMarks;

    //Insertion
    studentMarks["Prachi"]=97;
    studentMarks["Amit"]=89;

    //Access
    cout<<"Prachi's Marks :"<<studentMarks["Prachi"]<<endl;

    // Check if key exists
    if(studentMarks.count("Amit")){
        cout<<"Amit is present \n";
    }
     // Erase
    studentMarks.erase("Amit");
     
    //size
     cout << "Total students: " << studentMarks.size() << endl;

     // Iterate
    for (auto pair : studentMarks) {
        cout << pair.first << " got " << pair.second << " marks\n";
    }

}