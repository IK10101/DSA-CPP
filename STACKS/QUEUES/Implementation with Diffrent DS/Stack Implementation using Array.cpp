//Stack Implementation using Array
#include <iostream>
using namespace std;
class Stack {
   private:
    int* arr;
    int top;
    int capacity;

   public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack is full" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1; // Return -1 to indicate the stack is empty
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};