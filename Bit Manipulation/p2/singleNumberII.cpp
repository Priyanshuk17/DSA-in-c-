#include<bits/stdc++.h>
using namespace std;

// First approach
// TC -> O(n * log m) + O(m)
// sc -> O(m)
// int singleNumII(vector<int> &nums) {
//     unordered_map<int, int> mpp;
//     for(int i=0;i<nums.size();i++) {
//         mpp[nums[i]]++;
//     }
//     for(auto it : mpp) {
//         if(it.second == 1) {
//             return it.first;
//         }
//     }
// } 

// second approach
// TC-> O(n*32)
// SC-> O(1)
// int singleNumII(vector<int> &nums) {
//     int ans = 0;
//     for(int bitIndex = 0;bitIndex<32;bitIndex++) {
//         int cnt = 0;
//         for(int i=0;i<nums.size();i++) {
//             if(nums[i] & (1 << bitIndex))
//                 cnt++;
//         }
//         if(cnt%3==1) {
//             ans = ans | (1 << bitIndex);
//         }
//     }
//     return ans;
// }

// Third approach
// TC -> O(n log n) + O(n/3);
// sc -> O(1)
// int singleNumII(vector<int> &nums) {
//     sort(nums.begin(),nums.end());
//     int n = nums.size();
//     for(int i = 1;i<n;i+=3) {
//         if(nums[i] != nums[i-1]){
//             return nums[i-1];
//         }
//     }
//     return nums[n-1];
// }

// Most optimal one 
// TC->O(n)
// SC->O(1)
int singleNumII(vector<int>& nums) {
    int ones = 0;
    int twos = 0;
    for(int i = 0;i<nums.size();i++) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
}

int main() {
    vector<int> nums = {5, 5, 5, 6, 4, 4, 4};
    int ans = singleNumII(nums);
    cout << ans;

    return 0;
}