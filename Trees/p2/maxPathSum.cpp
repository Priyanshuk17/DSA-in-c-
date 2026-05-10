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

int maxPathDown(Node* node, int &maxi) {
    if(node == NULL) {
        return 0;
    }
    int left = max(0, maxPathDown(node->left, maxi));
    int right = max(0, maxPathDown(node->right, maxi));

    maxi = max(maxi, left + right + node->data);
    return max(left, right) + node->data;
}

int maxPathSum(Node* root) {
    int maxi = INT_MIN;
    Node *node = root;
    maxPathDown(node, maxi);
    return maxi;
}


int main() {
    struct Node *root = new Node(-10);
    root->left = new Node(2);
    root->right = new Node(9);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);
    int ans = maxPathSum(root);
    cout << "the max Distance path this tree have is :- " << ans;
    return 0;
}