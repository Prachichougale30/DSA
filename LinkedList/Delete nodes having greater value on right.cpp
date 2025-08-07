#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
  Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node* compute(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    head = reverse(head);

    Node* curr = head;
    int maxVal = curr->data;

    while (curr != NULL && curr->next != NULL) {
        if (curr->next->data < maxVal) {
            // Delete the next node
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
            maxVal = curr->data;
        }
    }

    head = reverse(head);
    return head;
}
};