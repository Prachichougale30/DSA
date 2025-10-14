#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        // Phase 1: Detect the cycle
        do {
            slow = nums[slow];           // Move slow pointer by 1 step
            fast = nums[nums[fast]];     // Move fast pointer by 2 steps
        } while (slow != fast);
        
        // Phase 2: Find the starting point of the cycle (duplicate number)
        fast = nums[0];                  // Move fast pointer to the beginning
        while (slow != fast) {
            slow = nums[slow];           // Move both pointers one step at a time
            fast = nums[fast];
        }
        
        // The point where they meet is the duplicate number
        return slow;
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    
    Solution sol;
    int duplicate = sol.findDuplicate(nums);
    
    cout << "Duplicate number is: " << duplicate << endl;
    
    return 0;
}
