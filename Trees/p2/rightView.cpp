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

void recursion(Node* root, int level, vector<int> &res) {
    if(root == NULL) return;
    if(res.size() == level) res.push_back(root->data);
    recursion(root->right, level+1, res);
    recursion(root->left, level+1, res); 
}

vector<int> rightSideView(Node* root) {
    vector<int> res;
    recursion(root, 0, res);
    return res;
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);
    vector<int> ans = rightSideView(root);
    for(auto it : ans) {
        cout << it << " ";
    }
    return 0;
}