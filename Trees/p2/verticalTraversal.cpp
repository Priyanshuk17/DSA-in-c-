#include<bits/stdc++.h>////////////////
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// void dfs(Node* root,int x, int y, vector<tuple<int, int, int>> &nodes) {
//     if(!root) return;
//     dfs(root->left, x - 1, y + 1, nodes);
//     nodes.push_back({x, y, root->data});
//     dfs(root->right, x+1, y+1, nodes);
// }

// vector<vector<int>> verticalTraversal(Node* root) {
//     vector<tuple<int, int, int>> nodes;
//     dfs(root, 0, 0, nodes);
//     // sort by x then y then val
//     sort(nodes.begin(), nodes.end());
//     vector<vector<int>> ans;
//     int prevX = INT_MIN;
//     for(auto it : nodes) {
//         int x = get<0>(it);
//         int y = get<1>(it);
//         int data = get<2>(it);
//         if(x != prevX) {
//             ans.push_back({});
//             prevX = x;
//         }
//         ans.back().push_back(data);
//     }
//     return ans;
// }

// strivers Method using level order
vector<vector<int>> verticalTraversal(Node* root) {
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node*, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while(!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        Node* node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node->data);
        if(node->left) {
            todo.push({node->left, {x-1, y+1}});
        }
        if(node->right) {
            todo.push({node->right, {x+1, y+1}});
        }
    }
    vector<vector<int>> ans;
    for(auto p : nodes) {
        vector<int> col;
        for(auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    vector<vector<int>> ans = verticalTraversal(root);
    
    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}