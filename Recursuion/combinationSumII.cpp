#include <bits/stdc++.h>
using namespace std;

void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
    if (target == 0) {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < arr.size(); i++) {
        
        // skip duplicates
        if (i > ind && arr[i] == arr[i-1]) continue;

        // stop if element > target
        if (arr[i] > target) break;

        ds.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSumII(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(candidates.begin(), candidates.end()); // important
    findCombination(0, target, candidates, ans, ds);
    return ans;
}

int main() {
    vector<int> candidates = {1, 1, 1, 2, 2};
    int target = 4;
    vector<vector<int>> result = combinationSumII(candidates, target);
    for (auto &vec : result) {
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}