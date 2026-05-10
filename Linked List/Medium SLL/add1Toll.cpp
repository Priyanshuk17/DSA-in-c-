#include<bits/stdc++.h>
using namespace std;


// RECURSIVE
int addHelper(Node* temp) {
    if(temp == NULL) {
        return 1;
    }
    int carry = addHelper(temp->next);
    temp->data += carry;
    if(temp->data < 10) return 0;
    temp->data = 0;
    return 1;
}
Node* addOne(Node* head) {
    int carry = addHelper(head);
    if(carry == 1) {
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// ITERATIVE
Node* reverseList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* newHead = reverseList(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

Node* addOne1(Node* head) {
    head = reverseList(head);
    Node* temp = head;
    carry = 1;
    while(temp != NULL) {
        temp->data += carry;
        if(temp->data < 10) {
            carry = 0;
            break;
        }
        else {
            temp->data = 0;
            carry = 1;
        }
        temp  = temp->next;
    } 
    if(carry == 1) {
        Node* newNode = new Node(1);
        head = reverseList(head);
        newNode->next = head;
        return newNode;
    }
    head = reverseList(head);
    return head;
}


int main() {



    return 0;
}