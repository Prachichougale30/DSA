#include <iostream>
using namespace std;

void swapValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside function: a = " << a << ", b = " << b << endl;
}

int main() {
    int x = 5, y = 10;
    swapValue(x, y);
    cout << "Outside function: x = " << x << ", y = " << y << endl;
}