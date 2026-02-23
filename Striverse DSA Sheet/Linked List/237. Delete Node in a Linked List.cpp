#include <bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;    
          // Copy next node value
        ListNode* temp = node->next;     
         // Store next node
        node->next = temp->next;          
        // Bypass next node
        delete temp;                     
         // Delete next node
    }
};

