#include<bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        vector<int> i;
        while(head){
            i.push_back(head->data);
            head=head->next;
        }
        int start=0,end=i.size()-1;
        while(start<end){
            if(i[start]!=i[end]){
                return false;
            }
            start++;
            end--;       
        }
        return true;
    }
};