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

// By using recursion 
// TC -> O(n)
// SC -> O(h) recursion stack space
// int depthOfBinaryTree(Node* root) {
//     if(root == NULL) return 0;

//     int lh = depthOfBinaryTree(root->left);
//     int rh = depthOfBinaryTree(root->right);

//     return 1 + max(lh, rh);
// }


// By using Level order
// TC -> O(N)
// SC -> O(N) using queue data structure
int depthOfBinaryTree(Node* root) {
    if(root == NULL) return 0;
    queue<Node*> q;
    q.push(root);
    int depth = 0;
    while(!q.empty()) {
        int size = q.size();
        for(int i=0;i<size;i++) {
            Node* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        depth++;
    }
    return depth;
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    int ans = depthOfBinaryTree(root);
    cout << "Maximum depth of the tree:- " << ans;
    return 0;
}