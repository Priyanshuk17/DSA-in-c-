#include<bits/stdc++.h>
using namespace std;
// Brute TLE ho gya leetcode me
// int characterReplacement(string s, int k) {
//     int maxLen = 0;
//     int n = s.size();
//     for(int i = 0;i<n;i++) {
//         vector<int> hash(26, 0);
//         int maxF = 0;
//         for(int j=i;j<n;j++) {
//             hash[s[j] - 'A']++;
//             maxF = max(maxF, hash[s[j] - 'A']);
//             int changes = (j - i + 1) - maxF;
//             if(changes <= k){
//                 maxLen = max(maxLen, j - i + 1);
//             }
//             else {
//                 break;
//             }
//         }
//     }
//     return maxLen;
// }

// Optimal
// int characterReplacement(string s, int k) {
//     int l = 0;
//     int maxLen = 0;
//     vector<int> hash(26, 0);
//     for(int r = 0; r < s.size(); r++) {
//         hash[s[r] - 'A']++;
//         maxF = max(maxF, hash[s[r] - 'A']);
//         while((r - l + 1) - maxF > k) {
//             hash[s[l] - 'A']--;
//             l++;
//         }
//         maxLen = max(maxLen, r - l + 1);
//     }
//     return maxLen;
// }

int characterReplacement(string s, int k) {
    int l = 0, maxLen = 0, maxF = 0;
    vector<int> hash(26, 0);
    for(int r = 0; r < s.size(); r++) {
        hash[s[r] - 'A']++;
        maxF = max(maxF, hash[s[r] - 'A']);
        if((r - l + 1) - maxF > k) {
            hash[s[l] - 'A']--;  // remove left char
            l++;                 // shrink window
        }
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}

int main() {
    string s;
    cin >> s;
    int res = characterReplacement(s, 2);
    cout << res;
    return 0;
}
