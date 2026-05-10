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

void markParents(Node* root, unordered_map<Node*, Node*>& parent_track) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* current = q.front();
        q.pop();
        if(current->left) {
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if(current->right) {
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}

vector<int> distanceK(Node* root, Node* target, int k) {
    unordered_map<Node*, Node*> parent_track;
    markParents(root, parent_track);
    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;
    while(!q.empty()) {
        int size = q.size();
        if(curr_level++ == k) break;
        for(int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();
            // left child
            if(current->left && !visited[current->left]) {
                q.push(current->left);
                visited[current->left] = true;
            }
            // right child
            if(current->right && !visited[current->right]) {
                q.push(current->right);
                visited[current->right] = true;
            }
            // parent
            if(parent_track[current] && !visited[parent_track[current]]) {
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> result;
    while(!q.empty()) {
        Node* current = q.front();
        q.pop();
        result.push_back(current->data);
    }
    return result;
}

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

    Node* target = root->left; // Node 10
    int k = 2;
    vector<int> ans = distanceK(root, target, k);
    cout << "Nodes at distance " << k << " from target node "<< target->data << " are:\n";
    for(auto it : ans) {
        cout << it << " ";
    }
    return 0;
}