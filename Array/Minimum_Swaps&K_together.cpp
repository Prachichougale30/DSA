#include <bits/stdc++.h>
using namespace std;

int minSwaps(int arr[], int n, int k) {
    // Step 1: Count elements <= k
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k)
            count++;
    }

    // If no such elements or all are already together
    if (count == 0)
        return 0;

    // Step 2: Count bad elements (> k) in first window
    int bad = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] > k)
            bad++;
    }

    int ans = bad;

    // Step 3: Sliding window
    for (int i = 0, j = count; j < n; i++, j++) {
        // Remove the element going out
        if (arr[i] > k)
            bad--;

        // Add the element coming in
        if (arr[j] > k)
            bad++;

        ans = min(ans, bad);
    }

    return ans;
}

int main() {
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << minSwaps(arr, n, k);
    return 0;
}
