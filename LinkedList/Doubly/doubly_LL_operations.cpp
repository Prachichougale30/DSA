#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";

        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}

int getlength(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
void insertatHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void inserAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    temp->prev = tail;
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}
void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    // insert ata start
    if (position == 1)
    {
        insertatHead(head, d);
    }
    Node *temp = head;
    int cnt = 0;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // inserting at last position
    if (temp->next == NULL)
    {
        inserAtTail(tail, d);
        return;
    }
    Node *nodeToinsert = new Node(d);
    nodeToinsert->next = temp->next;
    temp->next->prev = nodeToinsert;
    temp->next = nodeToinsert;
    nodeToinsert->prev = temp;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertatHead(head, 11);
    print(head);

    insertatHead(head, 12);
    print(head);

    insertatHead(head, 13);
    print(head);
    inserAtTail(tail, 30);
    print(head);
    insertAtPosition(tail,head,3,17);
    print(head);
    return 0;
}