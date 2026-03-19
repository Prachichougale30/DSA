#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
      Node *next;
      Node() : val(0), next(nullptr) {}
      Node(int x) : val(x), next(nullptr) {}
      Node(int x, Node *next) : val(x), next(next) {}
  };

  class Solution{

    public:
    Node*reverseKgroup(Node*head,int k){
        Node*prev=NULL;
        Node*curr=head;
        Node*forw=NULL;

        int count=0;
        int totalNode=0;

        Node*temp=head;

        while(temp){
            totalNode++;
            temp=temp->next;
        }

        if(totalNode<k){
            return head;
        }

        while(curr&& count<k){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
            count++;
        }

        if(forw!=NULL){
            head->next=reverseKgroup(forw,k);
        }
        return prev;
    }

  };