#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int total = (1 << n);

    vector<vector<int>> ans;

    for(int i = 0; i < total; i++) {
        vector<int> ls;

        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                ls.push_back(nums[j]);
            }
        }

        ans.push_back(ls);
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    for(auto it : ans) {
        cout << "{";
        for(auto i : it) {
            cout  << i << " ";
        }
        cout << "}";
        cout << endl;
    }

    return 0;
}