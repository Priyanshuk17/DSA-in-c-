#include<bits/stdc++.h>
using namespace std;

// optimal
// int fruits(vector<int> &fruits) {
//     int l=0;
//     int maxLen = 0;
//     int n = fruits.size();
//     unordered_map<int, int> mp;
//     for(int r=0;r<n;r++) {
//         mp[fruits[r]]++;
//         if(mp.size() > 2) {
//             mp[fruits[l]]--;
//             if(mp[fruits[l]]==0) {
//                 mp.erase(fruits[l]);
//             }
//             l++;
//         }
//         maxLen = max(maxLen, r-l+1);
//     }
//     return maxLen;
// }

// brute
// int fruits(vector<int> &fruits) {
//     int n = fruits.size();
//     int maxLen = 0;
//     for(int i=0;i<n;i++) {
//         set<int> st;
//         for(int j=i;j<n;j++) {
//             st.insert(fruits[j]);
//             if(st.size() > 2) {
//                 break;
//             }
//             else {
//                 maxLen = max(maxLen, j - i + 1);
//             }
//         }
//     }
//     return maxLen;
// }

int fruits(vector<int>& fruits) {
    int l = 0;
    int r = 0;
    int maxLen = 0;
    unordered_map<int, int> mpp;
    while(r<fruits.size()) {
        mpp[fruits[r]]++;
        if(mpp.size() > 2) {
            while(mpp.size()>2) {
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]);
                }
                l++;
            }
        }
        if(mpp.size() <= 2) {
            maxLen = max(maxLen, r-l+1);
        }
        r++;
    }
    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 2};
    int ans = fruits(arr);
    cout << ans;
    return 0;
}