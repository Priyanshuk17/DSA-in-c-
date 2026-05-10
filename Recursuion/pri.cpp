#include<bits/stdc++.h>
using namespace std;

void solve(int ind, vector<int> &ds,vector<int> &arr, int s, vector<vector<int>> &ans) {
    int n = arr.size();
    if(ind == n) {
        if()
    }
    ds.push_back(arr[ind]);
    solve(ind + 1, ds, arr, ans);
    ds.pop_back();
    solve(ind + 1, ds, arr, ans);
}

vector<vector<int>> findSubsequence(vector<int> &arr, int sum) {
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0, ds, arr, sum, ans);
    return ans;
}

int main() {
    vector<int> arr = {3, 1, 2};
    vector<vector<int>> result = findSubsequence(arr);
    for(auto it : result) {
        cout << "{";
        for( auto i : it) {
            cout << " "<< i;
        }
        cout <<  "}";
        cout << endl;
    }

    return 0;
}