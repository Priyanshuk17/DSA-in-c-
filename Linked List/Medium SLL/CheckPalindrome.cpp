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

// Node* reverseLL(Node* head) {
//     if(head == NULL || head->next == NULL) return head;
//     Node* newHead = reverseLL(head->next);
//     Node* front = head->next;
//     front->next = head;
//     head->next = NULL;
//     return newHead;
// }

// bool isPalindrome(Node* head) {
//     if(head == NULL || head->next == NULL) return true;
//     Node* slow = head;
//     Node* fast = head;
//     while(fast->next!=NULL && fast->next->next != NULL) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     Node* newHead = reverseLL(slow->next);
//     Node* first = head;
//     Node* second = newHead;
//     while(second != NULL) {
//         if(first->data != second->data) {
//             reverseLL(newHead);
//             return false;
//         }
//         first = first->next;
//         second = second->next;
//     }
//     reverseLL(newHead);
//     return true;
// }

bool isPalindrome(Node* head) {
    stack<int> st;
    Node* temp = head;
    while(temp!=NULL) {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL) {
        if(temp->data != st.top())
            return false;
        temp = temp->next;
        st.pop();
    }
    return true;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(1);
    Node* fourth = new Node(2);
    Node* fifth = new Node(1);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    bool ans = isPalindrome(head);
    cout << ans;
    
    return 0;
}