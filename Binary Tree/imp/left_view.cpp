#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            // Traverse one level
            for (int i = 0; i < n; i++) {
                Node* frontNode = q.front();
                q.pop();

                // The first node of every level is part of the left view
                if (i == 0) {
                    ans.push_back(frontNode->data);
                }

                if (frontNode->left) {
                    q.push(frontNode->left);
                }
                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }
        }

        return ans;
    }
};
