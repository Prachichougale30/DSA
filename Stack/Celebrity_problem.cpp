#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool knows(vector<vector<int>> &mat, int a, int b) {
        return mat[a][b] == 1;
    }
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        stack<int> s;
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        // Step 1: Find potential celebrity
        while (s.size() > 1) {
            int a = s.top(); 
            s.pop();
            int b = s.top();
             s.pop();

            if (knows(mat, a, b)) {
                s.push(b);  // a knows b -> a cannot be celebrity
            } else {
                s.push(a);  // a doesn't know b -> b cannot be celebrity
            }
        }

        
        int ans = s.top();

        // Step 2: Verify candidate
        // Row check: candidate should not know anyone
        for (int i = 0; i < n; i++) {
            if (i != ans && mat[ans][i] == 1) {
                return -1;
            }
        }

        // Column check: everyone should know candidate
        for (int i = 0; i < n; i++) {
            if (i != ans && mat[i][ans] == 0) {
                return -1;
            }
        }

        return ans;
    }
};
