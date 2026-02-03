#include<bits/stdc++.h>
using namespace std;

vector<int> factorial(int n) {
    vector<int> digits;
    digits.push_back(1);   // 1! = 1

    for (int i = 2; i <= n; i++) {
        int carry = 0;

        for (int j = 0; j < digits.size(); j++) {
            int prod = digits[j] * i + carry;
            digits[j] = prod % 10;
            carry = prod / 10;
        }

        // handle remaining carry
        while (carry) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    reverse(digits.begin(), digits.end());
    return digits;
}
