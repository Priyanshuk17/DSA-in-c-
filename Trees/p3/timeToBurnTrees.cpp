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

int findMaxDistance(unordered_map<Node*, Node*> &mpp, Node* target) {
    queue<Node*> q;
    q.push(target);
    unordered_map<Node*, int> vis;
    vis[target] = 1;
    int maxi = 0;
    while(!q.empty()) {
        int sz = q.size();
        int fl = 0;
        for(int i=0;i<sz;i++) {
            Node* node = q.front();
            q.pop();
            if(node->left && !vis[node->left]) {
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if(node->right && !vis[node->right]) {
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if(mpp[node] && !vis[mpp[node]]) {
                fl = 1;
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }
        if(fl) maxi++;
    }
    return maxi;

}

Node* bfsToParents(Node* root, unordered_map<Node*, Node*>& mpp, int start) {
    queue<Node*> q;
    q.push(root);
    Node* res;
    while(!q.empty()) {
        Node* node = q.front();
        if(node->data == start) res = node;
        q.pop();
        if(node->left) {
            mpp[node->left] = node;
            q.push(node->left);
        }
        if(node->right) {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

Node* bfsToParents(Node* root, unordered_map<Node*, Node*>& mpp, int start) {
    queue<Node*> q;
    q.push(root);
    Node* res;
    while(!q.empty()) {
        Node* node = q.front();
        if(node->data == start) res = node;
        q.pop();
        if(node->left) {
            mpp[node->left] = node;
            q.push(node->left);
        }
        if(node->right) {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

int timeToBurnTree(Node* root, int start) {
    unordered_map<Node*, Node*> mpp;
    Node* target = bfsToParents(root, mpp, start);
    int maxi = findMaxDistance(mpp, target);
    return maxi;
}
// leetcode 2385 question bhi same hai
// question name Amount of time for Binary tree needed to get infected
int main() {
    /*
             40
            /  \
          10    20
         / \    / \
        2   5  30  40
    */
    Node* root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(20);

    root->left->left = new Node(2);
    root->left->right = new Node(5);

    root->right->left = new Node(30);
    root->right->right = new Node(40);

    
    int start = 10;
    int ans = timeToBurnTree(root, start);
    cout << "Time to burn tree from " <<  " node " << start << " is" << ans;
    
    return 0;
}