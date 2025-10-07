#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();       // Get array size
        map<int, int> m;           // Frequency map
        int f = n / 2;             // Majority threshold
        cout << "n/2 = " << f << endl; // Debug print
        
        for (int i = 0; i < n; i++) {
            ++m[nums[i]];          // Increase frequency of nums[i]
            
            // If frequency exceeds n/2, it's the majority element
            if (m[nums[i]] > f) {
                return nums[i];
            }
        }
        return 0; // Default return (should not reach here if input has majority)
    }
};

int main() {
    Solution s;

    // Example input
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    // Find majority element
    int result = s.majorityElement(nums);

    cout << "Majority Element: " << result << endl;

    return 0;
}
