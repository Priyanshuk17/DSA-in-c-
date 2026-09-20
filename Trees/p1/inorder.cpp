#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
//  this question is to print the inorder traversal of a binary tree.
//  how to do it:-
// 1. take the root of the binary tree as input.
// 2. if the root is NULL, then return.
// 3. recursively call the inorder function for the left subtree.
// 4. print the data of the root.
// 5. recursively call the inorder function for the right subtree.
// 6. finally, return the result.
void inorder(Node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root -> data << " ";
    inorder(root->right);
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    inorder(root);

    return 0;
}