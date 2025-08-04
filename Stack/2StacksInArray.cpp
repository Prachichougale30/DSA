#include <bits/stdc++.h>
using namespace std;

class twoStacks {
public:
    int *arr;
    int top1;
    int top2;
    int size;

    twoStacks(int s) {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int x) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = x;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void push2(int x) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = x;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            return -1;
        }
    }

    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            return -1;
        }
    }
};

int main() {
    twoStacks ts(5);
    ts.push1(10);
    ts.push1(20);
    ts.push2(30);
    ts.push2(40);

    cout << ts.pop1() << endl;
    cout << ts.pop2() << endl;

    return 0;
}
