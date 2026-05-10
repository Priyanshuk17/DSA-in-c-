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

void solve(Node* root, string path, vector<string> &ans) {
    if(root==NULL) {
        return;
    }
    path += to_string(root->data);
    if(root->left==NULL && root->right==NULL) {
        ans.push_back(path);
        return;
    }
    path += "->";
    solve(root->left, path, ans);
    solve(root->right, path, ans);
}

vector<string> getAll(Node* root) {
    vector<string> ans;
    solve(root, "", ans);
    return ans;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    int target = 6;

    vector<string> ans = getAll(root);

    for(string x : ans){
        cout << x << " ";
    }
    return 0;
}