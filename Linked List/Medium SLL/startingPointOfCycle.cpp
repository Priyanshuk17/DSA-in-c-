#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* firstNode(Node* head) {
    unordered_set<Node*> st;
    Node* temp = head;
    while(temp!=NULL) {
        // already visited
        if(st.find(temp) != st.end()) {
            return temp;
        }
        st.insert(temp);
        temp = temp->next;
    }
    return NULL;
}

Node* firstNode(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            slow = head;
            while(slow!=fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

Node* firstNode(Node* head) {
    unordered_set<Node*> st;
    Node* temp = head;
    while(temp != NULL) {
        // already visited
        if(st.find(temp) != st.end()) {
            return temp;
        }
        st.insert(temp);
        temp = temp->next;
    }
    return NULL;
}

Node *firstNode(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main() {

    Node* head = new Node(2);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = new Node(4);

    // Creating cycle
    head->next->next->next->next->next->next = head->next->next;

    Node* ans = firstNode(head);

    if(ans != NULL) {
        cout << "Starting node of cycle: " << ans->data;
    }
    else {
        cout << "No cycle";
    }

    return 0;
}