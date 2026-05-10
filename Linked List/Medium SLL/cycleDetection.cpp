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

bool hasCycle(Node *head) {
    if (head == NULL || head->next == NULL)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;  // cycle detected
    }
    return false; // no cycle
}

// bool hasCycle(Node* head) {
//     unordered_set<Node*> mpp;
//     Node* temp = head;
//     while(temp!=NULL) {
//         if(mpp.find(temp)!=mpp.end()) {
//             return true;
//         }
//         mpp.insert(temp);
//         temp = temp->next;
//     }
//     return false;
// }

int main() {
    Node* head = new Node(2);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = head->next->next; // cycle here

    bool ans = hasCycle(head);
    cout << ans;

    return 0;
}