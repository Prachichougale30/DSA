#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*next;

    Node(int val){
        data=val;
        next=NULL;
    }

};

Node* insertAtHead(Node* head, int val) {
    Node* newNode = new Node(val);  // Step 1
    newNode->next = head;           // Step 2
    head = newNode;                 // Step 3
    return head;                    // Step 4
}