#include<bits/stdc++.h>
using namespace std;

vector<int> productOfArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    // left pass
    int left = 1;
    for(int i=0;i<n;i++) {
        ans[i] = left;
        left *= nums[i];
    } 

    // right pass
    int right = 1;
    for(int i=n-1;i>=0;i--) {
        ans[i] *= right;
        right *= nums[i];
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = productOfArray(nums);

    for(auto it : result) {
        cout << it << " ";
    }

    return 0;
}