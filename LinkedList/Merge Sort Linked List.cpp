#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *sortLL(Node *head)
{
    // Write your code here.
    vector<int> v;
    Node *temp = head;
    while (temp)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    sort(v.begin(), v.end());
    Node *newNode = new Node(-1);
    Node *tail = newNode;
    for (int val : v)
    {
        tail->next = new Node(val);
        tail = tail->next;
    }
    return newNode->next;
}