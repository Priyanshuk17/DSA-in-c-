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

Node* build(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inMap) {
    if(postStart > postEnd || inStart > inEnd) return NULL;
    Node* root = new Node(postorder[postEnd]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = build(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, inRoot-1, inMap);
    root->right = build(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, inMap);
    return root;
}

Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inMap;
    for(int i=0;i<inorder.size();i++) {
        inMap[inorder[i]] = i;
    }
    Node* root = build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    return root;
}

void inorderTr(Node *root) {
    if(root == NULL) {
        return;
    }
    inorderTr(root->left);
    cout << root -> data << " ";
    inorderTr(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    Node* ans = buildTree(inorder, postorder);
    inorderTr(ans);
    return 0;
}