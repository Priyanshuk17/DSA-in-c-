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

//Brute
// TC->O(2N)
// SC->O(N) for storing arr elements
// Node* oddEvenList(Node* head) {
//     if(head==NULL || head->next==NULL) {
//         return head;
//     }
//     vector<int> arr;
//     Node* temp = head;
//     while(temp!=NULL && temp->next!=NULL) {
//         arr.push_back(temp->data);
//         temp = temp->next->next;
//     }
//     if(temp != NULL) arr.push_back(temp->data);
//     temp = head->next;
//     while(temp!=NULL && temp->next!=NULL) {
//         arr.push_back(temp->data);
//         temp = temp->next->next;
//     }
//     if(temp != NULL) arr.push_back(temp->data);
//     int i = 0;
//     temp = head;
//     while(temp!=NULL) {
//         temp->data = arr[i];
//         i++;
//         temp = temp->next;
//     }
//     return head;
// }
//Optimal
Node* oddEvenList(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;

    while(even!=NULL && even->next!=NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
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

    head = oddEvenList(head);

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    return 0;
}