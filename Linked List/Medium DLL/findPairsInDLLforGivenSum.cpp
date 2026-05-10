#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* findTail(Node* head) {
    Node* tail = head;
    while(tail->next != NULL) tail = tail->next;
    return tail;
}

vector<pair<int, int>> findPairs(Node* head, int k) {
    vector<pair<int, int>> ans;
    if(head == NULL) return ans;
    Node* left = head;
    Node* right = findTail(head);
    while(left->data < right->data) {
        if(left->data + right->data == k) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
        }
        else if(left->data + right->data < k) {
            left = left->next;
        }
        else right = right->back;
    }
    return ans;
}
int main() {

    // Creating a sorted Doubly Linked List: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
    Node* head = new Node(1);
    Node* n1 = new Node(2);
    Node* n2 = new Node(3);
    Node* n3 = new Node(4);
    Node* n4 = new Node(5);
    Node* n5 = new Node(6);

    head->next = n1;

    n1->back = head;
    n1->next = n2;

    n2->back = n1;
    n2->next = n3;

    n3->back = n2;
    n3->next = n4;

    n4->back = n3;
    n4->next = n5;

    n5->back = n4;

    // Print function
    auto printList = [&](Node* h){
        while(h != NULL){
            cout << h->data << " ";
            h = h->next;
        }
        cout << endl;
    };

    cout << "Doubly Linked List: ";
    printList(head);

    int k = 7;

    vector<pair<int,int>> result = findPairs(head, k);

    cout << "Pairs with sum = " << k << " : ";
    for(auto &p : result){
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
