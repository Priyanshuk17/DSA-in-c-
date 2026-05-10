#include<bits/stdc++.h>
using namespace std;

// approach 1
// void recurPermute(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, vector<bool> &freq) {
//     if(ds.size() == nums.size()) {
//         ans.push_back(ds);
//         return;
//     }
//     for(int i = 0;i<nums.size();i++) {
//         if(!freq[i]) {
//             freq[i] = true;
//             ds.push_back(nums[i]);
//             recurPermute(nums, ds, ans, freq);
//             ds.pop_back();
//             freq[i] = false;
//         }
//     }
// }

// vector<vector<int>> permute(vector<int> &nums) {
//     int n = nums.size();
//     vector<vector<int>> ans;
//     vector<int> ds;
//     vector<bool> freq(n);
//     recurPermute(nums, ds, ans, freq);
//     return ans;
// }

// approach 2
void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans) {
    if(index == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for(int i = index;i<nums.size();i++) {
        swap(nums[index], nums[i]);
        recurPermute(index+1, nums, ans);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    recurPermute(0, nums, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);
    for(auto it : result) {
        for(auto i : it) {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}