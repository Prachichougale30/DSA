#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {

    Node* front;
    Node* rear;
    int count;

  public:
    myQueue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int x) {
        Node* temp = new Node(x);

        if (rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }

        count++;
    }

    void dequeue() {
        if (front == nullptr) return;

        Node* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
        count--;
    }

    int getFront() {
        if (front == nullptr) return -1;
        return front->data;
    }

    int size() {
        return count;
    }
};