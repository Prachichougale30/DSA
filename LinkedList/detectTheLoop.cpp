#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        map<Node*,int> m;
        
        while(head){
            if(m.count(head)){
                return true;
            }
            ++m[head];
            head=head->next;
            
        }
        return false; 
    }
};