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
  int length(Node *head){
      int cnt = 0;
    while(head){
        cnt++;
        head=head->next;
    }
      return cnt;
  }

  Node *insertInMiddle(Node *head, int x) {
      Node* newNode = new Node(x);

      if (!head) return newNode;

      int n = length(head);
      int idx = (n - 1) / 2;          

      Node* curr = head;
      for (int i = 0; i < idx; ++i) { 
          curr = curr->next;
      }

      newNode->next = curr->next;     
      curr->next = newNode;
      return head;
  }
};