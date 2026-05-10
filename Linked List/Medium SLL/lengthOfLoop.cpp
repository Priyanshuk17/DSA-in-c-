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

// int lengthOfLoop(Node* head) {
//     unordered_map<Node*, int> mpp;
//     Node* temp = head;
//     int timer = 0;
//     while(temp!=NULL) {
//         if(mpp.find(temp)!=mpp.end()) {
//             return timer - mpp[temp];
//         }
//         mpp[temp] = timer;
//         timer++;
//         temp = temp->next;
//     }
//     return 0;
// }

// int findLength(Node* slow, Node* fast) {
//     int cnt = 1;
//     fast = fast->next;
//     while(slow != fast) {
//         cnt++;
//         fast = fast->next;
//     }
//     return cnt;
// }

// int lengthOfLoop(Node* head) {
//     Node* slow = head;
//     Node* fast = head;
//     while(fast != NULL || fast->next != NULL) {
//         slow = slow->next;
//         fast = fast->next->next;
//         if(slow == fast) {
//             return findLength(slow, fast);
//         }
//     }
//     return 0;
// }


int main() {
    Node* head = new Node(1);
    Node* second = new Node(1);
    Node* third = new Node(1);
    Node* fourth = new Node(1);
    Node* fifth = new Node(1);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;
    int loopLength = lengthOfLoop(head);
    if(loopLength > 0)
        cout << "Length of the loop is: " << loopLength << endl;
    else
        cout << "No loop detected." << endl;
    return 0;
}