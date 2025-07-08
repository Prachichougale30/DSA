#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
void deleteNode(int position, Node *&head)
{
    // deleting first or strat node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start node;
        temp->next=NULL;
        delete temp; // destructore create
    }
    else
    {
        // delete middle or last node
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt <= position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        delete curr;
    }
}
void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
int main(){
    Node* node1=new Node(10);
   // cout<<node1->data<<endl;

    Node*head=node1;

    deleteNode(1,head);
    print(head);
}