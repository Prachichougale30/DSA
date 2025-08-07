#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    // Should return head of the modified linked list
  Node* sortedInsert(Node* head, int key) {
    Node* newNode = new Node(key);

    // Case 1: Insert at head
    if (head == NULL || key < head->data) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL && current->next->data < key) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}
};