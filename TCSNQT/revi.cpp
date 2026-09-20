#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val; 
        left = right = NULL;
    }
};

vector<vector<int>> levelOrderTraversal(Node* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++) {
            Node* node = q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

vector<int> iterativePreorder(Node* root) {
    vector<int> preorder;
    if(root==NULL) return preorder;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        Node* root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right!=NULL) {
            st.push(root->right);
        }
        if(root->left!=NULL) {
            st.push(root->left);
        }
    }
    return preorder;
}


vector<int> iterativeInorder(Node* root) {
    stack<Node*> st;
    Node* node = root;
    vector<int> inorder;
    while(true) {
        if(node!=NULL) {
            st.push(node);
            node = node->left;
        }
        else {
            if(st.empty()==true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}

vector<int> postorder(Node* root) {
    vector<int> postorder;
    if(root == NULL) return postorder;
    stack<Node*> st1, st2;
    st1.push(root);
    while(!st1.empty()) {
        Node* root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL) {
            st1.push(root->left);
        }
        if(root->right!=NULL) {
            st1.push(root->right);
        }
    }
    while(!st2.empty()) {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    vector<int> ans = postorder(root);
    for(auto it : ans) {
        cout<< it << " ";
    }
}