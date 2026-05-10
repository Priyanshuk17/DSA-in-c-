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

bool isSymmetricHelp(Node* left, Node* right) {
    if(left == NULL || right==NULL) return left==right;
    if(left->data != right->data) return false;
    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}

bool symmetric(Node* root) {
    return root==NULL || isSymmetricHelp(root->left, root->right);
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);
    bool ans = symmetric(root);
    cout << ans;
    return 0;
}