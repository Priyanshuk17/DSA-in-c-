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

vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> result;
    if(root == NULL) {
        return result;
    }
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()) {
        int size = q.size();
        vector<int> row(size);
        for(int i=0;i<size;i++) {
            Node* node = q.front();
            q.pop();
            int index = leftToRight ? i : (size-i-1);
            row[index] = node->data;
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}

int main() {
    struct Node *root = new Node(-10);
    root->left = new Node(2);
    root->right = new Node(9);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);
    vector<vector<int>> ans =  zigzagLevelOrder(root);
    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " "; 
        }
        cout << endl;
    }
    return 0;
}