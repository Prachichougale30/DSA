#include <bits/stdc++.h>
using namespace std;

struct Node  // ✅ Struct with capital N
{
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if (!head || k == 1) return head;

        Node* curr = head;
        Node* prev = NULL;
        Node* forw = NULL;

        int count = 0;

        // Count total nodes (optional)
        Node* temp = head;
        int totalNode = 0;
        while (temp) {
            totalNode++;
            temp = temp->next;
        }

        // Reverse first k nodes
        while (curr && count < k) {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
            count++;
        }

        // Recurse for remaining list
        if (forw != NULL) {
            head->next = reverseKGroup(forw, k);
        }

        return prev;
    }
};
