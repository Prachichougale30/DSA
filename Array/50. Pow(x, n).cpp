#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // Convert n to long long to handle overflow (when n = -2^31)
        long long power = n;
        double ans = 1.0;

        // If exponent is negative, make it positive
        if (power<0){
            power=-power;
        }
        // Binary exponentiation (fast power)
        while (power > 0) {
            // If current power is odd → multiply once
            if (power % 2 == 1) {
                ans *= x;
            }
            // Square the base
            x *= x;
            // Divide the exponent by 2
            power /= 2;
        }

        // If original n was negative → take reciprocal
        if (n < 0) {
            ans = 1.0 / ans;
        }

        return ans;
    }
};
