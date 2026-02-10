#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
  
  Node* createParentMapping(Node* root, int target,
                            map<Node*, Node*>& nodeToParent) {
      Node* res = NULL;
      queue<Node*> q;
      
      q.push(root);
      nodeToParent[root] = NULL;
      
      while(!q.empty()) {
          Node* front = q.front();
          q.pop();
          
          if(front->data == target)
              res = front;
          
          if(front->left) {
              nodeToParent[front->left] = front;
              q.push(front->left);
          }
              
          if(front->right) {
              nodeToParent[front->right] = front;
              q.push(front->right);
          }      
      }
      return res;
  }
  
  int burnTree(Node* root, map<Node*, Node*>& nodeToParent) {
      map<Node*, bool> visited;
      queue<Node*> q;
      
      q.push(root);
      visited[root] = true;
      
      int ans = 0;
      while(!q.empty()) {
          bool flag = false;
          int size = q.size();
          
          for(int i = 0; i < size; i++) {
              Node* front = q.front();
              q.pop();
              
              if(front->left && !visited[front->left]) {
                  flag = true;
                  visited[front->left] = true;
                  q.push(front->left);
              }
              
              if(front->right && !visited[front->right]) {
                  flag = true;
                  visited[front->right] = true;
                  q.push(front->right);
              }
              
              if(nodeToParent[front] &&
                 !visited[nodeToParent[front]]) {
                  flag = true;
                  visited[nodeToParent[front]] = true;
                  q.push(nodeToParent[front]);
              }
          }
          
          if(flag) ans++;
      }
      return ans;
  }
  
  int minTime(Node* root, int target) {
      if(!root) return 0;
      map<Node*, Node*> nodeToParent;
      Node* targetNode =
          createParentMapping(root, target, nodeToParent);
      return burnTree(targetNode, nodeToParent);
  }
};
