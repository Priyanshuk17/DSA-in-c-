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
// this question is to print the inorder traversal of a binary tree iteratively.
// how to do it:-
// 1. take the root of the binary tree as input.
// 2. create a stack to store the nodes of the binary tree.
// 3. create a vector to store the inorder traversal of the binary tree.
// 4. create a pointer to the root of the binary tree.
// 5. while the pointer is not NULL or the stack is not empty, do the
// following:-
//  a. if the pointer is not NULL, push the pointer to the stack and move the pointer to the left child of the pointer.
//  b. if the pointer is NULL, pop the top element from the stack and add the data of the popped element to the vector. Move the pointer to the right child of the popped element.  
// 6. finally, return the vector containing the inorder traversal of the binary tree.
vector<int> inorderTraversal(Node* root) {
    stack<Node*> st;
    Node *node = root;
    vector<int> inorder;
    while(true) {
        if(node != NULL) {
            st.push(node);
            node = node -> left;
        }
        else {
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node -> right;
        }
    }
    return  inorder;
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);
    
    vector<int> ans = inorderTraversal(root);
    for(auto it : ans) {
        cout << it << " ";
    }

    return 0;
}