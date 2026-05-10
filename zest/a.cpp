#include<bits/stdc++.h>
using namespace std;

// vector<int> mergeTwoSorted(vector<int> &arr1, vector<int> &arr2) {
//     int n = arr1.size();
//     int m = arr2.size();
//     vector<int> ans;
//     int left = 0;
//     int right = 0;
//     while(left < n && right < m) {
//         if(arr1[left] <= arr2[right]) {
//             ans.push_back(arr1[left]);
//             left++;
//         }
//         else {
//             ans.push_back(arr2[right]);
//             right++;
//         }

//     }
//     if(left<n) {
//         for(int i=left;i<n;i++) {
//             ans.push_back(arr1[i]);
//         }
//     }
//     if(right<m) {
//         for(int j=right;j<m;j++) {
//             ans.push_back(arr2[j]);
//         }
//     }
//     return ans;
// }

// void merge(vector<int> &arr1, vector<int> &arr2) {
//     int n = arr1.size();
//     int m = arr2.size();
//     int right = n-1;
//     int left = 0;
//     while(right >=0 && left < m) {
//         if(arr1[right] > arr2[left]) {
//             swap(arr1[right], arr2[left]);
//             right--;
//             left++;
//         }
//         else{
//             break;
//         }
//     }
//     sort(arr1.begin(), arr1.end());
//     sort(arr2.begin(), arr2.end());
// }

// void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2) {
//     if(arr1[ind1] > arr2[ind2]) {
//         swap(arr1[ind1], arr2[ind2]);
//     }
// }

// void merge(vector<int> &arr1, vector<int> &arr2) {
//     int n = arr1.size();
//     int m = arr2.size();
//     int len = n + m;
//     int gap = (len / 2) + (len % 2);
//     while(gap > 0) {
//         int left = 0;
//         int right = left + gap;
//         while(right<len) {
//             // left is in arr1 and right is in arr2
//             if(left < n && right >= n) {
//                 swapIfGreater(arr1, arr2, left, right-n);
//             }
//             else if(left >= n) {
//                 swapIfGreater(arr2, arr2, left-n, right-n);
//             }
//             else {
//                 swapIfGreater(arr1, arr1, left, right);
//             }
//             left++;
//             right++;
//         }
//         if(gap==1) break;
//         gap = (gap/2) + (gap%2);
//     }    
// }
// vector<int> repeatingMissing(vector<int> &arr) {
//     int n = arr.size();
//     // s - sn
//     // s2 - s2n
//     long long sn = (n * (n + 1)) / 2;
//     long long s2n = (n * (n+1) * (2*n+1)) / 6;
//     long long s = 0;
//     long long s2 = 0;
//     for(int i=0;i<n;i++) {
//         s += arr[i];
//         s2 += (long long)arr[i] * (long long)arr[i];
//     }
//     long long val1 = s - sn;
//     long long val2 = s2 - s2n;
//     val2 = val2 / val1;
//     long long x = (val1 + val2) / 2;
//     long long y = x - val1;

//     return {(int)x, (int)y};
// }

int maxProduct(vector<int> &arr) {
    int n = arr.size();
    int prefix = 1;
    int suffix = 1;
    int maxi;
    for(int i=0;i<n;i++) {
        if(prefix == 0) prefix = 1;
        if(sufiix == 0) suffix = 1;
        prefix = prefix * arr[i];
        suffix = suffix * arr[n-i-1];
        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
}

int main() {
    vector<int> arr1 = {1, 1, 2, 4, 5, 6};
    vector<int> ans = repeatingMissing(arr1);
    for(auto it : ans) {
        cout << it << " ";
    }

    // merge(arr1, arr2);
    // for(auto it : arr1) {
    //     cout << it << " ";
    // }
    // cout << endl;
    // for(auto it : arr2) {
    //     cout << it << " ";
    // }
    return 0;
}