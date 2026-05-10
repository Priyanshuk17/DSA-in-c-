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

Node* deleteMiddle(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    fast = head->next->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* middle = slow->next;
    slow->next = slow->next->next;
    delete middle;
    return head;
}


// Node* deleteMiddle(Node* head) {
//     Node* temp = head;
//     int cnt = 0;
//     while(temp!=NULL) {
//         cnt++;
//         temp = temp->next;
//     }
//     int res = cnt/2;
//     temp = head;
//     while(temp!=NULL) {
//         res--;
//         if(res==0) {
//             Node* delNode = temp->next;
//             temp->next = temp->next->next;
//             delete delNode;
//         }
//         temp = temp->next;
//     }
//     return head;
// }


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

    head = deleteMiddle(head);

    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}