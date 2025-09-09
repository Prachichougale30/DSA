#include <iostream>
using namespace std;

class MyCircularQueue {
    int *arr;
    int size;
    int front;
    int rear;

public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        else if (isEmpty()) {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) {
            rear = 0;  // wrap around
        }
        else {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // --- Original bool version of deQueue (commented out) ---
    /*
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            front = rear = -1;  // only one element
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
        return true;
    }
    */

    // --- Modified version: return dequeued value ---
    int deQueue() {
        if (isEmpty()) {
            return -1;  // if empty
        }
        int ans = arr[front];  // store value being removed

        if (front == rear) {
            // only one element
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0; // wrap around
        }
        else {
            front++;
        }
        return ans;
    }

    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size));
    }
};

// --- Example usage ---
int main() {
    MyCircularQueue q(3);

    cout << (q.enQueue(10) ? "Enqueued 10\n" : "Failed\n");
    cout << (q.enQueue(20) ? "Enqueued 20\n" : "Failed\n");
    cout << (q.enQueue(30) ? "Enqueued 30\n" : "Failed\n");
    cout << (q.enQueue(40) ? "Enqueued 40\n" : "Failed\n"); // should fail (queue full)

    cout << "Front: " << q.Front() << "\n";
    cout << "Rear: " << q.Rear() << "\n";

    cout << "Dequeued: " << q.deQueue() << "\n"; // returns value
    cout << "Dequeued: " << q.deQueue() << "\n";

    cout << "Front after dequeues: " << q.Front() << "\n";
    cout << "Rear after dequeues: " << q.Rear() << "\n";

    cout << (q.enQueue(40) ? "Enqueued 40\n" : "Failed\n"); // should succeed (wrap around)

    cout << "Front: " << q.Front() << "\n";
    cout << "Rear: " << q.Rear() << "\n";

    return 0;
}
