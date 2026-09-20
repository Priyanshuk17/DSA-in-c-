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

string serialize(Node* root) {
    if(!root) return "";
    string s = "";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* currNode = q.front();
        q.pop();
        if(currNode == NULL) {
            s.append("#,");
        }
        else s.append(to_string(currNode->data) + ",");
        if(currNode) {
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }
    return s;
}

Node *deserialize(string data) {
    if(data.size()==0) return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    Node* root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* currNode = q.front();
        q.pop();
        getline(s, str, ',');
        if(str == "#") {
            currNode->left = NULL;
        }
        else {
            Node* leftHead = new Node(stoi(str));
            currNode->left = leftHead;
            q.push(leftHead);
        }
        getline(s, str, ',');
        if(str == "#") {
            currNode->right = NULL;
        }
        else {
            Node* rightHead = new Node(stoi(str));
            currNode->right = rightHead;
            q.push(rightHead);
        }
    }
    return root;
}

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Original Tree
    /*
             1
            / \
           2   3
              / \
             4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    // Serialize
    string serializedTree = serialize(root);
    cout << "Serialized Tree:\n";
    cout << serializedTree << endl;
    // Deserialize
    Node* newRoot = deserialize(serializedTree);
    // Print inorder traversal
    cout << "\nInorder Traversal After Deserialization:\n";
    inorder(newRoot);
    return 0;
}