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

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeTwoLists(Node* head1, Node* head2) {
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(head1!=NULL && head2!=NULL) {
        if(head1->data<head2->data) {
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        }
        else {
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }
    if(head1) temp->next = head1;
    else temp->next = head2;

    return dummyNode->next;
}
Node* sortList(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node* middle = findMiddle(head);
    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;

    left = sortList(left);
    right = sortList(right);
    return mergeTwoLists(left, right);
}

// Node* sortList(Node* head) {
//     vector<int> arr;
//     Node* temp = head;
//     while(temp!=NULL) {
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }
//     sort(arr.begin(), arr.end());
//     int i = 0;
//     temp = head;
//     while(temp!=NULL) {
//         temp->data = arr[i];
//         i++;
//         temp = temp->next;
//     }
//     return head;
// }

int main() {
    Node* head = new Node(7);
    Node* second = new Node(4);
    Node* third = new Node(3);
    Node* fourth = new Node(2);
    Node* fifth = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    fifth->next = nullptr;

    head = sortList(head);

    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}