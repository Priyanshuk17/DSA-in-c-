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