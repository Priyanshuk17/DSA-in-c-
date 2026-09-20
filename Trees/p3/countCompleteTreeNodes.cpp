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

int findHeightLeft(Node* node) {
    int hght = 0;
    while(node) {
        hght++;
        node = node->left;
    }
    return hght;
}

int findHeightRight(Node* node) {
    int hght = 0;
    while(node) {
        hght++;
        node = node->right;
    }
    return hght;
}
int countNodes(Node* root) {
    if(root==NULL) return 0;
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if(lh == rh) return (1<<lh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
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

    int ans = countNodes(root);
    cout << "Count of this Complete Binary Tree is:- " << ans;
    
    return 0;
}