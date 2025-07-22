#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> majorityElement(vector<int>& arr) {
    unordered_map<int, int> freq;
    int n = arr.size();

    // Step 1: Count frequency of each element
    for (int num : arr) {
        freq[num]++;
    }

    // Step 2: Collect elements with frequency > n/3
    vector<int> result;
    for (auto it : freq) {
        if (it.second > n / 3) {
            result.push_back(it.first);
        }
    }

    // Step 3: Sort the result
    sort(result.begin(), result.end());
    return result;
}

// Driver code
int main() {
    vector<int> arr = {2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    vector<int> ans = majorityElement(arr);

    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}
