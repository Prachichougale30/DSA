#include <bits/stdc++.h>
using namespace std;
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution
{
public:
    // Function to reverse a doubly linked list
    DLLNode *reverseDLL(DLLNode *head)
    {
        // Your code here
        DLLNode *curr = head;
        DLLNode *temp = NULL;
        if (!head || !head->next)
            return head;
        while (curr != NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;
        }
        if (temp != nullptr)
        {
            head = temp->prev;
        }
        return head;
    }
};