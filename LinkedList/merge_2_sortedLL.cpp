
#include<bits/stdc++.h>
using namespace std;

// Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution
{
public:
    Node *sortedMerge(Node *head1, Node *head2)
    {
        // code here
        vector<int> one;
        while (head1)
        {
            one.push_back(head1->data);
            head1 = head1->next;
        }
        while (head2)
        {
            one.push_back(head2->data);
            head2 = head2->next;
        }
        sort(one.begin(), one.end());

        Node *newNode = new Node(-1);
        Node *tail = newNode;

        for (int val : one)
        {
            tail->next = new Node(val);
            tail = tail->next;
        }
        return newNode->next;
    }
};