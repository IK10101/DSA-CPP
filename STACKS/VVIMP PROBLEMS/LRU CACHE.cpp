// Design a data structure that follows the constraints of Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity): We need to initialize the LRU cache with positive size capacity.

// int get(int key): Returns the value of the key if the key exists, otherwise return -1.

// void put(int key,int value): Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.


// The functions get and put must each run in O(1) average time complexity.

// Note : In Input is provided in 2D array format where the first number in each array denotes the operation (1-put, 2-get) to perform. The next integers are the values used for the operation.




//Implementation
#include<bits/stdc++.h>
using namespace std;

class Node {
   public:
    int key, val;
    Node* next;
    Node* prev;

    Node() {
        key = val = -1;
        next = prev = NULL;
    }

    Node(int k, int value) {
        key = k;
        val = value;
        next = prev = NULL;
    }
};

class LRUCache {
   private:
    map<int, Node*> mpp;
    int cap;
    Node* head;
    Node* tail;

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        nextNode->prev = node;
        node->prev = head;
        node->next = nextNode;
    }

   public:
    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();

        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;

        Node* node = mpp[key];
        int val = node->val;

        deleteNode(node);

        insertAfterHead(node);

        return val;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;

            deleteNode(node);

            insertAfterHead(node);

            return;
        }

        if (mpp.size() == cap) {
            Node* node = tail->prev;

            mpp.erase(node->key);

            deleteNode(node);
        }

        Node* newNode = new Node(key, value);

        mpp[key] = newNode;

        insertAfterHead(newNode);
    }
};