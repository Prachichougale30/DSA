#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int zeroCount = 0;

    // Print non-zero elements
    for (int i = 0; i < N; i++) {
        if (arr[i] != 0) {
            cout << arr[i] << " ";
        } else {
            zeroCount++;
        }
    }

    // Print zeros at the end
    for (int i = 0; i < zeroCount; i++) {
        cout << 0 << " ";
    }

    return 0;
}