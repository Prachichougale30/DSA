#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    bool areIdentical(Node *head1, Node *head2) {
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->data != temp2->data) {
                return false;  // Data mismatch
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        
        return (temp1 == NULL && temp2 == NULL);
    }
};