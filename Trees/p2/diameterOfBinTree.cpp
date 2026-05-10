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
int maxi = 0;
int maxDepth(Node* root) {
    if(root == NULL) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    // ✅ yahi pe diameter update kar diya
    maxi = max(maxi, lh + rh);
    return 1 + max(lh , rh);
}

int diameterOfBinaryTree(Node* root) {
    maxDepth(root);   // ✅ sirf call karna hai
    return maxi;
}

int height(Node* node, int &diameter) {
    if(!node) {
        return 0;
    }
    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);

    diameter = max(diameter, lh+rh);
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(Node* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);
    int ans = diameterOfBinaryTree(root);
    cout << "Diameter is:- " << ans;
    return 0;
}