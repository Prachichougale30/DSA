#include <bits/stdc++.h>
using namespace std;

class Kqueue {
public:
    int n;        // size of array
    int k;        // number of queues
    int *front;   // front indexes
    int *rear;    // rear indexes
    int *arr;     // main array
    int freeSpot; // beginning of free list
    int *next;    // next free or next element links

    Kqueue(int n, int k) {
        this->n = n;
        this->k = k;

        front = new int[k];
        rear = new int[k];
        arr = new int[n];
        next = new int[n];

        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freeSpot = 0;
    }

    void enqueue(int data, int qn) {
        // overflow
        if (freeSpot == -1) {
            cout << "No empty space is present" << endl;
            return;
        }

        // find index
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        // first element
        if (front[qn - 1] == -1) {
            front[qn - 1] = index;
        } else {
            next[rear[qn - 1]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[qn - 1] = index;

        // push element
        arr[index] = data;
    }

    int dequeue(int qn) {
        // underflow
        if (front[qn - 1] == -1) {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        // index to pop
        int index = front[qn - 1];

        // move front ahead
        front[qn - 1] = next[index];

        // manage free slots
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main(){
    Kqueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
       q.enqueue(25,1);

       cout<<q.dequeue(1)<<endl;
        cout<<q.dequeue(2)<<endl;
         cout<<q.dequeue(1)<<endl;
          cout<<q.dequeue(1)<<endl;
          cout<<q.dequeue(1)<<endl;
}