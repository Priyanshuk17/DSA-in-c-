#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector<vector<int>> preInPostTraversal(Node *root) {
    vector<int> pre, in, post;
    if(root == NULL) return {pre, in, post};
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    while(!st.empty()) {
        auto it = st.top();
        st.pop();
        // Preorder
        if(it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        // Inorder
        else if(it.second == 2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        // Postorder
        else {
            post.push_back(it.first->data);
        }
    }
    return {pre, in, post};
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    vector<vector<int>> res = preInPostTraversal(root);

    cout << "Pre: ";
    for(int x : res[0]) cout << x << " ";

    cout << "\nIn: ";
    for(int x : res[1]) cout << x << " ";

    cout << "\nPost: ";
    for(int x : res[2]) cout << x << " ";

    return 0;
}