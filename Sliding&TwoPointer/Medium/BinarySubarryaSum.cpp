#include<bits/stdc++.h>
using namespace std;

// int numSubarraysWithSum(vector<int>& nums, int goal) {
//     int cnt = 0;
//     int n = nums.size();
//     for(int i=0;i<n;i++) {
//         int sum = 0;
//         for(int j=i;j<n;j++) {
//             sum = sum + nums[j];
//             if(sum == goal) {
//                 cnt++;
//             }
//             else if(sum > goal) {
//                 break;
//             }
//             else {
//                 continue;
//             }
//         }
//     }
//     return cnt;
// }

// Optimal One TC -> O(n) SC -> O(1)
int countSumLessThanK(vector<int>& nums, int goal) {
    if (goal < 0) return 0; 

    int l = 0, r = 0;
    int sum = 0, cnt = 0;
    int n = nums.size();

    while (r < n) {
        sum += nums[r];

        while (sum > goal) {
            sum -= nums[l];
            l++;
        }

        cnt += (r - l + 1);
        r++;
    }
    return cnt;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int res1 = countSumLessThanK(nums, goal);
    int res2 = countSumLessThanK(nums, goal - 1);
    return res1 - res2;
}

int main() {

    vector<int> nums = {1, 0, 0, 1, 1, 0};
    int ans = numSubarraysWithSum(nums, 2);
    cout << ans;

    return 0;
}