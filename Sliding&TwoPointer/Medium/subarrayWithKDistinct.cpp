#include <bits/stdc++.h>
using namespace std;


// Helper function to count subarrays with at most K distinct integers
int atMostK(vector<int>& nums, int k) {
    int l = 0;
    int r = 0;
    int cnt = 0;
    unordered_map<int, int> mpp;
    while(r<nums.size()) {
        mpp[nums[r]]++;
        while(mpp.size() <= k) {
            mpp[nums[l]]--;
            if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
            l++;
        }
        cnt = cnt + (r - l + 1);
        r++;
    }
    return cnt;
}

// Main function to return number of subarrays with exactly K distinct integers
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

// Driver code
// galat aa rha h
int main() {
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << subarraysWithKDistinct(nums, k) << endl;
    return 0;
}