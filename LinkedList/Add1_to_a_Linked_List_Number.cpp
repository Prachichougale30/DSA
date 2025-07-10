#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *revLL(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *forw = NULL;

        while (curr)
        {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    Node *addOne(Node *head)
    {
        // Your Code here
        head = revLL(head);
        Node *temp = head;
        int carry = 1;
        while (head)
        {
            int sum = head->data + carry;
            head->data = sum % 10;
            // cout<<head->data<<" ";
            carry = sum / 10;
            head = head->next;
        }
        temp = revLL(temp);
        if (carry)
        {
            Node *lastNode = new Node(carry);
            lastNode->next = temp;
            temp = lastNode;
        }

        return temp;
        // return head of list after adding one
    }
};