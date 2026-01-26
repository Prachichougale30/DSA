#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> result;
       int n = nums.size();
       sort(nums.begin(), nums.end()); // Step 1: Sort the array
       for (int i = 0; i < n - 2; i++) {
           // Step 2: Skip duplicate values for the current number
           if (i > 0 && nums[i] == nums[i - 1]) continue;


           int target = -nums[i]; // We need two numbers that sum to -nums[i]
           int left = i + 1, right = n - 1;


           // Step 3: Two-pointer approach
           while (left < right) {
               int sum = nums[left] + nums[right];


               if (sum == target) {
                   // Found a valid triplet
                   result.push_back({nums[i], nums[left], nums[right]});


                   // Step 4: Skip duplicates for left and right pointers
                   while (left < right && nums[left] == nums[left + 1]) left++;
                   while (left < right && nums[right] == nums[right - 1]) right--;


                   left++;
                   right--;
               } else if (sum < target) {
                   left++; // Need a larger sum
               } else {
                   right--; // Need a smaller sum
               }
           }
       }


       return result;
   }
};


int main() {
   Solution sol;
   vector<int> nums = {-1, 0, 1, 2, -1, -4};
   vector<vector<int>> res = sol.threeSum(nums);


   for (auto triplet : res) {
       for (int num : triplet) {
           cout << num << " ";
       }
       cout << endl;
   }


   return 0;
}

