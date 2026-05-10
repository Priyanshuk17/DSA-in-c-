#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Leetcode 876 question number 
Node* midNode(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* midNode(Node* head) {
    Node* temp = head;
    int cnt = 0;
    while(temp!=NULL) {
        cnt++;
        temp = temp->next;   
    }
    int midNode = (cnt/2) + 1;
    temp = head;
    while(temp!=NULL) {
        midNode = midNode - 1;
        if(midNode == 0) break;
        temp = temp->next;
    }
    return temp;
}

int main() {
    Node* head = new Node(2);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(7);

    // Finding middle node
    Node* middle = midNode(head);

    cout << "Middle Node Value: " << middle->data;
    return 0;
}