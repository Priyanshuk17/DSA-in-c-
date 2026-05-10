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
bool getPath(Node* root, vector<int> &arr, int x) {
    if(!root) 
        return false;
    arr.push_back(root->data);
    if(root->data==x) {
        return true;
    }
    if(getPath(root->left, arr, x) || getPath(root->right, arr, x)){
        return true;
    }
    arr.pop_back();
    return false;
}
vector<int> solve(Node* A, int B) {
    vector<int> arr;
    if(A==NULL) {
        return arr;
    }
    getPath(A, arr, B);
    return arr;
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

    vector<int> ans = solve(root, target);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}