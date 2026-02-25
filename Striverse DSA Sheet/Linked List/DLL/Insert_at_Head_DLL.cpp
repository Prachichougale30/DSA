#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

Node* insertAtHead(Node* head, int data) {
    Node* newNode = new Node(data);

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;   // Link new node to current head
    newNode->prev = NULL;   // New node will be first node
    head->prev = newNode;   // Old head points back to new node

    return newNode;         // Return new head
}