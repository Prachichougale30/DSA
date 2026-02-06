#include <bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int>& arr, int a, int b) {
    int low = 0, mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] < a) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] >= a && arr[mid] <= b) {
            mid++;
        }
        else { // arr[mid] > b
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
