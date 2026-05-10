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

Node* deleteAllOcc(Node* head, int key) {
    Node* temp = head;
    while(temp!=NULL) {
        if(temp->data == key) {
            if(temp == head) {
                head = head->next;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->back;
            if(nextNode != NULL) nextNode->back = prevNode;
            if(prevNode != NULL) prevNode->next = nextNode;
            free(temp);
            temp = nextNode;
        }
        else {
            temp = temp->next;
        }
    }
    return head;
}

int main() {

    // Creating a doubly linked list: 10 <-> 20 <-> 30 <-> 20 <-> 40
    Node* head = new Node(10);
    Node* n1 = new Node(20);
    Node* n2 = new Node(30);
    Node* n3 = new Node(20);
    Node* n4 = new Node(40);

    head->next = n1;

    n1->back = head;
    n1->next = n2;

    n2->back = n1;
    n2->next = n3;

    n3->back = n2;
    n3->next = n4;

    n4->back = n3;

    // Function to print the list
    auto printList = [&](Node* head){
        Node* t = head;
        while(t != NULL){
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    };

    cout << "Original List: ";
    printList(head);

    int key = 20;
    head = deleteAllOcc(head, key);

    cout << "After deleting all occurrences of " << key << ": ";
    printList(head);

    return 0;
}