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

void solve(Node* root, vector<int> &path, vector<vector<int>> &ans) {
    if(root==NULL) {
        return;
    }
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL) {
        ans.push_back(path);
    }
    solve(root->left, path, ans);
    solve(root->right, path, ans);
    path.pop_back();
}

vector<vector<int>> getAll(Node* root) {
    vector<int> path;
    vector<vector<int>> ans;
    solve(root, path, ans);
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

    vector<vector<int>> ans = getAll(root);

    for(auto x : ans) {
        for(int it : x) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}