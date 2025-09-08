#include <bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is full" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if (qfront == rear) {
            return -1;  // Queue empty
        } else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear) {
                // Reset queue if it becomes empty
                qfront = 0;
                rear = 0;
            }
            return ans;  // ✅ FIXED: return the dequeued element
        }
    }

    int front() {
        if (qfront == rear) {
            return -1;  // Queue empty
        } else {
            return arr[qfront];  // ✅ FIXED: return front element
        }
    }

    bool isEmpty() {
        return (qfront == rear);
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl; // should print 10
    cout << "Dequeued: " << q.dequeue() << endl;    // should print 10
    cout << "Dequeued: " << q.dequeue() << endl;    // should print 20
    cout << "Front element: " << q.front() << endl; // should print 30
    cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
