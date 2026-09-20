#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> func(vector<int> &arr) {
    unordered_map<int, int> mpp;
    vector<vector<int>> ans;
    for(int x : arr) {
        mpp[x]++;
    }
    for(auto it : mpp) {
        ans.push_back({it.first, it.second});
    }
    return ans;
}

int main() {
    vector<int> arr = {10, 20, 10, 20, 5};

    vector<vector<int>> res = func(arr);

    for(auto it : res) {
        cout << it[0] << " -> " << it[1] << endl;
    }

    return 0;
}