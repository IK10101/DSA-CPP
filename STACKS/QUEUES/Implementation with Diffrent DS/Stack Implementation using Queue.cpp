//Stack Implementation using Queue
#include <iostream>
#include <queue>
using namespace std;
class Stack {
   private:
    queue<int> q1;
    queue<int> q2;

   public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        swap(q1, q2);
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1; // Return -1 to indicate the stack is empty
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topElement = q1.front();
        q2.push(topElement);
        q1.pop();
        swap(q1, q2);
        return topElement;
    }

    bool isEmpty() {
        return q1.empty();
    }
};