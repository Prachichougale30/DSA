#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution {
  public:
  
    Node* findTail(Node* head){
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        return temp;
    }
  
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int,int>> ans;
        
        if(head == NULL) return ans;
        
        Node* left = head;
        Node* right = findTail(head);
        
        while(left != right && right->next != left){
            
            int sum = left->data + right->data;
            
            if(sum == target){
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if(sum < target){
                left = left->next;
            }
            else{
                right = right->prev;
            }
        }
        
        return ans;
    }
};