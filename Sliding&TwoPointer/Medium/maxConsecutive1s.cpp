#include<bits/stdc++.h>
using namespace std;


// better one 
int longestOnes(vector<int>& nums, int k) {
    int maxLen = 0;
    int n = nums.size();
    int l = 0;
    int r = 0;
    int zeros = 0;
    while(r<n) {
        if(nums[r] == 0) {
            zeros++;
        }
        while(zeros > k) {
            if(nums[l] == 0) zeros--;
            l++;
        }
        if(zeros<=k) {
            int len = r - l + 1;
            maxLen = max(maxLen, len);
        }
        r++;
    }
    return maxLen;
}

// int longestOnes(vector<int>& nums, int k) {
//     int maxLen = 0;
//     int n = nums.size();
//     int l = 0;
//     int r = 0;
//     int zeros = 0;
//     while(r<n) {
//         if(nums[r] == 0) zeros++;
//         if(zeros > k) {
//             if(nums[l] == 0) zeros--;
//             l++;
//         }
//         if(zeros <= k) {
//             int len = r - l + 1;
//             maxLen = max(maxLen, len);
//         }
//         r++;
//     }
//     return maxLen;
// }

int main () {
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    int ans = longestOnes(arr, k);
    cout << ans;
    return 0;
}