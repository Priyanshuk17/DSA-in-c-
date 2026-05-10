ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> visited;

    // Traverse the first list and store all node addresses
    ListNode* currentA = headA;
    while (currentA != nullptr) {
        visited.insert(currentA);
        currentA = currentA->next;
    }

    // Traverse the second list and check for intersection
    ListNode* currentB = headB;
    while (currentB != nullptr) {
        if (visited.find(currentB) != visited.end()) {
            return currentB; // Intersection found
        }
        currentB = currentB->next;
    }

    // No intersection
    return nullptr;
}

// Better solution
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;
    
    // Compute lengths
    int lenA = 0, lenB = 0;
    ListNode* p = headA;
    while (p) { ++lenA; p = p->next; }
    p = headB;
    while (p) { ++lenB; p = p->next; }
    
    // Advance the longer list by the difference
    int diff = abs(lenA - lenB);
    ListNode* a = headA;
    ListNode* b = headB;
    if (lenA > lenB) {
        while (diff--) a = a->next;
    } else if (lenB > lenA) {
        while (diff--) b = b->next;
    }
    
    // Move both pointers together until they meet
    while (a && b) {
        if (a == b) return a; // intersection
        a = a->next;
        b = b->next;
    }
    
    return nullptr; // no intersection
}
// Optimal
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL) return NULL;
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;
    while(temp1 != temp2) {
    temp1 = temp1->next;
    temp2 = temp2->next;

    if(temp1 == temp2) return temp1;

    if(temp1 == NULL) temp1 = headB;
    if(temp2 == NULL) temp2 = headA;
    }
    return temp1;
}