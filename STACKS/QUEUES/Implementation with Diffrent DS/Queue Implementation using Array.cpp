// Queue Implementation using Array
#include <iostream>
using namespace std;
class Queue {
   private:
    int* arr;
    int front;
    int rear;
    int capacity;

   public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int x) {
        if (rear == capacity - 1) {
            cout << "Queue is full" << endl;
            return;
        }
        rear++;
        arr[rear] = x;
    }

    void dequeue() {
        if (front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        front++;
    }

    int peek() {
        if (front > rear) {
            cout << "Queue is empty" << endl;
            return -1; // Return -1 to indicate the queue is empty
        }
        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }
};