#include <bits/stdc++.h>
using namespace std;
class Node{

    int data;
    Node*next;

    Node(int x){
        data=x;
        next=NULL;
    }


int length(Node*head){
    int len=0;

    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}
Node*middleNode(Node*head){
    int mid=length(head)/2;
    Node*temp=head;
    int cnt=0;

    while(cnt<mid){
        temp=temp->next;
        cnt++;
    }
    return temp;
}
};