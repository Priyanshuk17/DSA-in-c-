#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int depthOfBinaryTree(Node* root) {
    if(root == NULL) return 0;
    int lh = depthOfBinaryTree(root->left);
    if(lh == -1) return -1;
    int rh = depthOfBinaryTree(root->right);
    if(rh == -1) return -1;
    if(abs(lh-rh) > 1) return -1;
    return 1 + max(lh, rh);
}

bool checkBalanced(Node* root) {
    return depthOfBinaryTree (root) != -1;
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);
    bool ans = checkBalanced(root);
    cout << "the Tree is you have give is :- " << ans << " balanced";
    return 0;
}