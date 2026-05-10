#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root==NULL || root==p || root == q) {
        return root;
    }
    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);
    if(left == NULL) {
        return right;
    }
    else if(right==NULL) {
        return left;
    }
    else { // both left and right are not null, we found our result
        return root;
    }
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);
    Node* ans = lowestCommonAncestor(root, root->left->right->left, root->right);
    cout << ans->data;
    return 0;
}