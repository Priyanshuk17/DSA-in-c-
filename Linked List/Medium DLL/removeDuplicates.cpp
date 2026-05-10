
Node* removeDuplicates(Node* head) {
    Node* temp = head;
    while(temp->next != NULL && temp != NULL) {
        Node* nextNode = temp->next;
        while(nextNode != NULL && nextNode->data == temp->data) {
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        temp->next = nextNode;
        if(nextNode != NULL) nextNode->prev = temp;
    }
    return head;
}