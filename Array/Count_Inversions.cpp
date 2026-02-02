#include<bits/stdc++.h>
using namespace std;

long long merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;
    long long invCount = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            invCount += (mid - i + 1);  // 
        }
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= end)
        temp.push_back(arr[j++]);

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }

    return invCount;
}

long long mergeSort(vector<int> &arr, int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;

        long long leftInv = mergeSort(arr, st, mid);
        long long rightInv = mergeSort(arr, mid + 1, end);
        long long crossInv = merge(arr, st, mid, end);

        return leftInv + rightInv + crossInv;
    }
    return 0;
}
    int inversionCount(vector<int> &arr) {
      return mergeSort(arr,0,arr.size()-1);
}
int main(){
  vector<int> arr = {2, 4, 1, 3, 5};
    cout << mergeSort(arr, 0, arr.size() - 1);
}