#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int key; 
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public: 
    int capacity;
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail; 

    // constructor
    LRUCache(int cap) {
        capacity = cap;
        mpp.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    // delete a node from DLL
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* afterNode = node->next;
        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }
    // insert node just after head
    void insertAfterHead(Node* node) {
        Node* curAfterHead = head->next;
        head->next = node;
        node->prev = head;
        node->next = curAfterHead;
        curAfterHead->prev = node;
    }
    int get(int key) {
        if(mpp.find(key) == mpp.end()) 
            return -1;
        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    void put(int key, int value) {
        // key already exists
        if(mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else {
            // cache full
            if(mpp.size() == capacity) {
                Node* lru = tail->prev;
                mpp.erase(lru->key);
                deleteNode(lru);
            }
            Node* node = new Node(key, value);
            mpp[key] = node;
            insertAfterHead(node);
        }
    }
};

int main() {
    LRUCache cache(2); // capacity = 2
    cache.put(1, 10);
    cache.put(2, 20);
    cout << cache.get(1) << endl;
    cache.put(3, 30);
    cout<< cache.get(2) << endl;
    cache.put(4, 40);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
    return 0;
}