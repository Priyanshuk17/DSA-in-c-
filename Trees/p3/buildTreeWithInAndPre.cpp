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

Node* build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inMap) {
    if(preStart > preEnd || inStart > inEnd) return NULL;
    Node* root = new Node(preorder[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = build(preorder, preStart+1, preStart + numsLeft, inorder, inStart, inRoot-1, inMap);
    root->right = build(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for(int i=0;i<inorder.size();i++) {
        inMap[inorder[i]] = i;
    }
    Node* root = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
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
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> preorder = {10, 20, 40, 50, 30, 60};
    Node* ans = buildTree(preorder, inorder);
    inorderTr(ans);
    return 0;
}