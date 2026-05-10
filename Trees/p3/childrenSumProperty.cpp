#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void changeTree(Node* root) {
    if(root == NULL) return;
    int child = 0;
    // children sum calculate
    if(root->left) {
        child += root->left->data;
    }
    if(root->right) {
        child += root->right->data;
    }
    // if children sum greater
    if(child >= root->data) {
        root->data = child;
    }
    else {
        // push parent value downward
        if(root->left) {
            root->left->data = root->data;
        }
        else if(root->right) {
            root->right->data = root->data;
        }
    }
    // recursion
    changeTree(root->left);
    changeTree(root->right);
    // backtracking step
    int total = 0;
    if(root->left) {
        total += root->left->data;
    }
    if(root->right) {
        total += root->right->data;
    }
    // update parent
    if(root->left || root->right) {
        root->data = total;
    }
}

// inorder traversal
void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->left = new Node(30);
    root->right->right = new Node(40);
    cout << "Before Change:\n";
    inorder(root);
    cout << endl;
    changeTree(root);
    cout << "After Change:\n";
    inorder(root);
    cout << endl;
    return 0;
}