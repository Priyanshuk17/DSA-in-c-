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

int widthOfBinaryTree(Node* root) {
    if(!root) {
        return 0;
    }
    int ans = 0;
    queue<pair<Node*, long long>> q;
    q.push({root, 0});
    while(!q.empty()) {
        int size = q.size();
        int mmin = q.front().second;
        long long first, last;
        for(int i=0;i<size;i++) {
            long long curr_id = q.front().second - mmin;
            Node* node = q.front().first;
            q.pop();
            if(i==0) first = curr_id;
            if(i==size-1) last = curr_id;
            if(node->left) {
                q.push({node->left, curr_id*2+1});
            }
            if(node->right) {
                q.push({node->right, curr_id*2+2});
            }
        }
        ans = max(ans, (int)(last-first+1));
    }
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
    int ans = widthOfBinaryTree(root);
    cout << ans;
    return 0;
}