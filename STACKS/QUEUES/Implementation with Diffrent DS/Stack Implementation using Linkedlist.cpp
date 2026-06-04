//Stack Implementation using Linked List
#include <iostream>
using namespace std;
class Node {
public:    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class Stack {
private:    Node* top;
public:    Stack() {
        top = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1; // Return -1 to indicate the stack is empty
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};