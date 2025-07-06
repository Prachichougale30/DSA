#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        map<Node* ,int>m;
        int len=0;
        while(head){
          ++len;
          //loop check
          if(m.count(head)){
              return len-m[head];
          }
          m.insert({head,len});
          head=head->next;
        }
        return 0;
    }
};