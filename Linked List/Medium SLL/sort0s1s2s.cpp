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

Node* sortList(Node* head) {
    if(!head || !head->next) return head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    Node* temp = head;
    while(temp) {
        if(temp->data == 0) {
            zero->next = temp;
            zero = temp;
        } else if(temp->data == 1) {
            one->next = temp;
            one = temp;
        } else {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    zero->next = (oneHead->next)?(oneHead->next):(twoHead->next);
    one->next = twoHead->next;
    two->next = NULL;

    Node* newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
}

// Node* sortList(Node* head) {
//     Node* temp = head;
//     int cnt0 = 0, cnt1 = 0, cnt2 = 0;
//     while(temp!=NULL) {
//         if(temp->data == 0) cnt0++;
//         else if(temp->data == 1) cnt1++;
//         else cnt2++;
//         temp = temp->next;
//     }
//     temp = head;
//     while(temp!=NULL) {
//         if(cnt0) {
//             temp->data = 0;
//             cnt0--;
//         }
//         else if(cnt1) {
//             temp->data = 1;
//             cnt1--;
//         }
//         else{
//             temp->data = 2;
//             cnt2--;
//         }
//         temp = temp->next;
//     }
//     return head;
// }
int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(0);
    Node* fourth = new Node(0);
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