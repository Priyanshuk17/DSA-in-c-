#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool isSameTree(Node* p, Node* q) {
    if(p==NULL && q==NULL) return true;

    if(p==NULL || q==NULL) return false;
    if(p->data != q->data) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// bool isSameTree(TreeNode* p, TreeNode* q) {
//     if(p == NULL || q == NULL) {
//         return (p==q);
//     }

//     return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
// }

int main() {
    struct Node *p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(7);
    p->left->left = new Node(3);
    p->left->right = new Node(4);
    p->left->right->left = new Node(5);
    p->left->right->right = new Node(6);

    struct Node *q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(7);
    q->left->left = new Node(3);
    q->left->right = new Node(4);
    q->left->right->left = new Node(5);
    q->left->right->right = new Node(6);

    bool ans = isSameTree(p, q);

    cout << ans;

    return 0;
}