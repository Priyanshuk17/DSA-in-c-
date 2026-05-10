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
bool isLeaf(Node* root) {
    return !root->left && !root->right;
}
void addLeftBoundary(Node* root, vector<int> &res) {
    Node* curr = root->left;
    while(curr) {
        if(!isLeaf(curr)) {
            res.push_back(curr->data);
        }
        if(curr->left) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
}
void addRightBoundary(Node* root, vector<int> &res) {
    Node* curr = root->right;
    vector<int> tmp;

    while(curr) {
        if(!isLeaf(curr)) tmp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(int i=tmp.size()-1;i>=0;i--) {
        res.push_back(tmp[i]);
    }
}

void addLeaves(Node* root, vector<int> &res) {
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}
vector<int> printBoundary(Node* root) {
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
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

    vector<int> ans = printBoundary(root);
    for(auto it : ans) {
        cout << it << " ";
    }
    return 0;
}