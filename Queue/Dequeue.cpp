#include <bits/stdc++.h>
using namespace std;

class Deque {
    int *arr;
    int size;
    int front;
    int rear;

public:
    // Initialize your data structure.
    Deque(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Pushes 'X' in the front of the deque.
    bool pushFront(int x) {
        if (isFull()) {
            return false;
        } else if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque.
    bool pushRear(int x) {
        if (isFull()) {
            return false;
        } else if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque.
    int popFront() {
        if (isEmpty()) {
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) { // single element
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0; // cyclic nature
        } else {
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque.
    int popRear() {
        if (isEmpty()) {
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear) { // single element
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque.
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    // Returns the last element of the deque.
    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    // Returns true if the deque is empty.
    bool isEmpty() {
        return (front == -1);
    }

    // Returns true if the deque is full.
    bool isFull() {
        return ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size));
    }
};

// Example usage
int main() {
    Deque dq(5);

    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushFront(5);
    dq.pushFront(3);

    cout << "Front: " << dq.getFront() << endl; // 3
    cout << "Rear: " << dq.getRear() << endl;   // 20

    cout << "Popped front: " << dq.popFront() << endl; // 3
    cout << "Popped rear: " << dq.popRear() << endl;   // 20

    cout << "Front: " << dq.getFront() << endl; // 5
    cout << "Rear: " << dq.getRear() << endl;   // 10
}
