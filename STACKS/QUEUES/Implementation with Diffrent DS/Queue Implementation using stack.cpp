// Queue Implementation using Stack
#include <iostream>
#include <stack>
using namespace std;
class Queue {
   private:
    stack<int> s1;
    stack<int> s2;

   public:
    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        s2.pop();
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            cout << "Queue is empty" << endl;
            return -1; // Return -1 to indicate the queue is empty
        }
        return s2.top();
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};