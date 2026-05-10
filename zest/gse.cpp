#include<bits/stdc++.h>
using namespace std;


// int maxLength(vector<int>& arr, int k) {
//     int l = 0;
//     int r = 0;
//     int sum = 0;
//     int maxLen = 1;
//     while(r<arr.size()) {
//         sum = sum + arr[r];
//         if(sum > k) {
//             sum = sum - arr[l];
//             l = l + 1;
//         }
//         if(sum <= k) {
//             maxLen = max(maxLen, r - l + 1);
//         }
//         r = r + 1;
//     }
//     return maxLen;
// }

// int maxPoint(vector<int> &arr, int k) {
//     int lsum = 0;
//     int rsum = 0;
//     int maxSum = 0;
//     for(int i=0;i<k;i++) {
//         lsum = lsum + arr[i];
//     }
//     maxSum = lsum;
//     ridx = n-1;
//     for(int i=k-1;i>-0;i--) {
//         lsum = lsum - arr[i];
//         rsum = rsum + arr[ridx];
//         ridx--;

//         maxSum = max(maxSum, lsum + rsum);
//     }
//     return maxSum;
// }

// int subarray(vector<int> &arr) {
//     int n = arr.size();
//     int maxLen = 0;
//     for(int i=0;i<n;i++) {
//         int hash[256] = {0};
//         for(int j=i;j<n;j++) {
//             if(hash[j]==1) break;
//             maxLen = max(maxLen, j-i+1);
//             hash[arr[j]]=1;
//         }
//     }
//     return maxLen;
// }

// int longestSubstring(string s) {
//     int l=0;
//     int r = 0;
//     int n = s.size();
//     int maxLen = 0;
//     int hash[256] = {-1};
//     while(r<n) {
//         if(hash[s[r]] != -1) {
//             if(hash[s[r]] >= l) {
//                 l = hash[s[r]]+1;
//             }
//         }
//         maxLen = max(maxLen, r - l + 1);
//         hash[s[r]] = r;
//         r++;
//     }
//     return maxLen;
// }

int maxConsecutive(vector<int> &arr, int k) {
    int n = arr.size();
    int maxLen = 0;
    int l = 0, r = 0, zeros = 0;
    while(r<n) {
        if(arr[r] == 0) zeros++;
        if(zeros>k) {
            if(arr[l]==0) zeros--;
            l++;
        }
        if(zeros<=k) {
            int len = r - l + 1;
            maxLen = max(len, maxLen);
        }
        r++;
    }
    return maxLen;
}



int main() {
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int ans = maxConsecutive(arr, 2);
    cout << ans;

    return 0;
}