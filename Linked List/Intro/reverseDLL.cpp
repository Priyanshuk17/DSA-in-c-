#include<bits/srdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data, Node* next, Node* back) {
        this->data = data;
        this->next = next;
        this->prev = back;
    }

    public:
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// one pass solution
// reverse two number logic is used here
Node* reverseDLL(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev = NULL;
    Node* current = head;
    while(current != NULL) {
        prev = current->prev;
        current->prev = current->next;
        current->next = prev;

        current = current->prev;
    }
    return prev->prev;
} 

// two pass solution
Node* reverseDll(Node* head) {
    Node* temp = head;
    stack<int> st;
    while(temp!=NULL) {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

int main() {


    return 0;
}