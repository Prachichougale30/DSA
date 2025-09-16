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

}*head;

class Solution {
  public:
    Node* pairWiseSwap(Node* head) {
         if (!head || !head->next) return head;

    Node* newHead = head->next;  // second node becomes new head
    Node* previousNode = nullptr;
    Node* currentNode = head;

    while (currentNode && currentNode->next) {
        Node* firstNode = currentNode;
        Node* secondNode = currentNode->next;

        // Swap the pair
        firstNode->next = secondNode->next;
        secondNode->next = firstNode;

        if (previousNode) {
            previousNode->next = secondNode;  // connect previous pair to current swapped pair
        }


        // Move to the next pair
        previousNode = firstNode;
        currentNode = firstNode->next;

}
    return newHead;
    }
};