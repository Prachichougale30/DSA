#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Push back
    void pb(deque<int>& dq, int x) {
        dq.push_back(x);
    }

    // Pop back
    void ppb(deque<int>& dq) {
        if (!dq.empty()) {
            dq.pop_back();
        }
    }

    // Return front element
    int front_dq(deque<int>& dq) {
        if (!dq.empty()) {
            return dq.front();
        }
        return -1; // or handle error if needed
    }

    // Push front
    void pf(deque<int>& dq, int x) {
        dq.push_front(x);
    }
};
int main() {
    Solution sol;
    deque<int> dq;

    sol.pf(dq, 5);   // [5]
    sol.pf(dq, 10);  // [10, 5]
    sol.pb(dq, 6);   // [10, 5, 6]

    cout << sol.front_dq(dq) << endl;  // Output: 10

    sol.ppb(dq);     // [10, 5]

    cout << sol.front_dq(dq) << endl;  // Output: 10
    return 0;
}
