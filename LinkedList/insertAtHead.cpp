#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
Node* insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return head;
}
void inserAtEnd(Node *&head,int data){
   
    while(head->next!=nullptr){
        head = head->next;
    }
    Node *newTail= new Node(data);
    head->next=newTail;
}
void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}
int main()
{
    Node *head = new Node(10);

    Node *temp=head;
    temp=insertAtHead(head, 20);
    temp=insertAtHead(head, 30);
    temp=insertAtHead(head, 60);
    inserAtEnd(head,57);
    printList(temp);

    return 0;
}