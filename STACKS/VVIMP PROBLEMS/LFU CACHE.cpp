// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// Implement the LFUCache class with the following functions:

// LFUCache(int capacity): Initialize the object with the specified capacity.

// int get(int key): Retrieve the value of the key if it exists in the cache; otherwise, return -1.

// void put(int key, int value): Update the value of the key if it is present in the cache, or insert the key if it is not already present. If the cache has reached its capacity, invalidate and remove the least frequently used key before inserting a new item. In case of a tie (i.e., two or more keys with the same frequency), invalidate the least recently used key.


// A use counter is maintained for each key in the cache to determine the least frequently used key. The key with the smallest use counter is considered the least frequently used.

// When a key is first inserted into the cache, its use counter is set to 1 due to the put operation. The use counter for a key in the cache is incremented whenever a get or put operation is called on it.

// Ensure that the functions get and put run in O(1) average time complexity.


//Implementation
#include<bits/stdc++.h>
using namespace std;

class Node {
   public:
    int key, value, cnt;
    Node* next;
    Node* prev;

    Node(int _key, int _value) {
        key = _key;
        value = _value;
        cnt = 1;
        next = nullptr;
        prev = nullptr;
    }
};

class List {
   public:
    int size;
    Node* head;
    Node* tail;

    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;

        size = 0;
    }

    void addFront(Node* node) {
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;

        size++;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        size--;
    }
};

class LFUCache {
   private:
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;

    int maxSizeCache;
    int minFreq;
    int curSize;

    void updateFreqListMap(Node* node) {
        keyNode.erase(node->key);

        freqListMap[node->cnt]->removeNode(node);

        if (node->cnt == minFreq &&
            freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        List* nextHigherFreqList;

        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        } else {
            nextHigherFreqList = new List();
        }

        node->cnt++;

        nextHigherFreqList->addFront(node);

        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

   public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];
        int value = node->value;

        updateFreqListMap(node);

        return value;
    }

    void put(int key, int value) {
        if (maxSizeCache == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];

            node->value = value;

            updateFreqListMap(node);
            return;
        }

        if (curSize == maxSizeCache) {
            List* list = freqListMap[minFreq];

            Node* nodeToDelete = list->tail->prev;

            keyNode.erase(nodeToDelete->key);
            list->removeNode(nodeToDelete);

            delete nodeToDelete;

            curSize--;
        }

        curSize++;

        minFreq = 1;

        List* listFreq;

        if (freqListMap.find(1) != freqListMap.end()) {
            listFreq = freqListMap[1];
        } else {
            listFreq = new List();
        }

        Node* node = new Node(key, value);

        listFreq->addFront(node);

        keyNode[key] = node;
        freqListMap[1] = listFreq;
    }
};