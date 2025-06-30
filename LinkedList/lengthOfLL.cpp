#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int new_data){
        data=new_data;
        next=nullptr;
    }
};

int countNodes(Node*head){
    int count=0;
    Node*curr=head;

    while (curr!=nullptr)
    {
        count++;
        curr=curr->next;
    }
    return count;
}
int main(){
    Node*head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);

    cout<<"Count of nodes is ->"<<countNodes(head);
}