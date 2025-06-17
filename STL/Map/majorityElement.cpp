#include <bits/stdc++.h>
using namespace std;

int MajorElement(vector<int> nums) {
    int size = nums.size();
    int f = size / 2;
    map<int, int> m;

    for (int i = 0; i < size; i++) {
        ++m[nums[i]];
        if (m[nums[i]] > f) {
            return nums[i];
        }
    }

    return 0; // Return 0 if no majority element (if not guaranteed)
}

int main() {
    vector<int> arr2 = {1, 3, 1, 1, 1, 2, 3};
    int major = MajorElement(arr2);

    if (major != 0)
        cout << "Majority Element is: " << major << endl;
    else
        cout << "No majority element found." << endl;

    return 0;
}
