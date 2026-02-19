#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> pq;

    // Step 1: Push first k elements into max heap
    for(int i = l; i < l + k; i++) {
        pq.push(arr[i]);
    }

    // Step 2: Process remaining elements
    for(int i = l + k; i <= r; i++) {
        if(arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout << "Kth Smallest Element: " 
         << kthSmallest(arr, 0, n-1, k);

    return 0;
}
