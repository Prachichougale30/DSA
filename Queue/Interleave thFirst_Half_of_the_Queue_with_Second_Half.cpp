#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    queue<int> rearrangeQueue(queue<int> q) {
        int n = q.size();
        int half = n / 2;
        stack<int> s;

        // Step 1: Push first half into stack
        for (int i = 0; i < half; i++) {
            s.push(q.front());
            q.pop();
        }

        // Step 2: Enqueue back elements from stack (reversed half)
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        // Step 3: Move first half (reversed) to back of queue
        for (int i = 0; i < half; i++) {
            q.push(q.front());
            q.pop();
        }

        // Step 4: Again push first half into stack
        for (int i = 0; i < half; i++) {
            s.push(q.front());
            q.pop();
        }

        // Step 5: Interleave stack and queue
        while (!s.empty()) {
            int val = s.top(); 
            s.pop();
            q.push(val);

            val = q.front(); 
            q.pop();
            q.push(val);
        }

        return q;
    }
};

int main() {
    Solution sol;
    queue<int> q;

    // Example input
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    queue<int> ans = sol.rearrangeQueue(q);

    // Print rearranged queue
    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;

    return 0;
}
