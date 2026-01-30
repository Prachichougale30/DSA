#include <bits/stdc++.h>
using namespace std;

void rotateByOne(vector<int>& arr) {
    int n = arr.size();
    
    // Edge case: single element
    if (n <= 1)
        return;

    int last = arr[n - 1];

    // Shift elements to the right
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    // Place last element at the front
    arr[0] = last;
}
