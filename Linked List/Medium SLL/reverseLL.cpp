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

 // RECURSIVE
Node* reverseList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* newHead = reverseList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

// ITERATIVE
Node* reverseList(Node* head) {
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL) {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

int main() {
    Node* head = new Node(2);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(7);

    // Reverse Linked List
    head = reverseListIterative(head);
    // head = reverseListRecursive(head);

    // Print Reversed Linked List
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "Middle Node Value: " << middle->data;
    return 0;
}