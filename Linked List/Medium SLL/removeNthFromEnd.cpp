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
Node* removeNthFromEnd(Node* head, int n) {
    Node* fast = head;
    Node* slow = head;
    for(int i=0;i<n;i++) {
        fast = fast->next;
    }
    if(fast == NULL) return head->next;
    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}
Node* removeNthFromEnd(Node* head, int n) {
    Node* fast = head;
    Node* slow = head;
    for(int i=0;i<n;i++) {
        fast = fast->next;
    }
    if(fast==NULL) return head->next;
    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}
Node* removeNthFromEnd(Node* end, int n) {
    Node* temp = head;
    int cnt = 0;
    while(temp!=NULL) {
        cnt++;
        temp = temp->next;
    }
    int res = cnt - n;
    temp = head;
    while(temp!=NULL) {
        res--;
        if(res==0) {
            break;
        }
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
    return head;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;
    head = removeNthFromEnd(head, 2);
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}