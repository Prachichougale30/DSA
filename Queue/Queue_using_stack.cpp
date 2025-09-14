#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> input, output;

  public:
    // Function to add an element to the queue
    void enqueue(int x) {
        input.push(x);
    }

    // Function to remove and return the front element of the queue
    int dequeue() {
        if (output.empty()) {
            // Transfer all elements from input to output
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        if (output.empty()) {
            return -1; // Queue is empty
        }
        int front = output.top();
        output.pop();
        return front;
    }
};
int main() {
    Queue q;
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << " "; // 2
    q.enqueue(4);
    cout << q.dequeue() << " "; // 3
    cout << q.dequeue() << " "; // 4
    cout << q.dequeue() << " "; // -1 (empty)
    return 0;
}
