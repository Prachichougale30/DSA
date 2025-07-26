#include<iostream>
#include <unordered_set>
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
    Node *removeDuplicates(Node *head) {
        unordered_set<int> s;
        Node* curr = head;
        Node* prev = nullptr;

        while (curr) {
            if (s.find(curr->data) != s.end()) {
                prev->next = curr->next;
               
                delete curr;
                curr = prev->next;
            } else {
                s.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};
