#include<bits/stdc++.h>
using namespace std;

// brute
// string longestCommonPrefix(vector<string> &strs) {
//     if(strs.empty()) return "";

//     string prefix = strs[0];
//     for(int i = 1;i<strs.size();i++) {
//         int j = 0;
//         while(j<prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
//             j++;
//         }
//         prefix = prefix.substr(0, j);
//         if(prefix == "") return "";
//     }
//     return prefix;
// }

string commonPrefix(string left, string right) {
    int len = min(left.size(), right.size());
    
    for (int i = 0; i < len; i++) {
        if (left[i] != right[i]) {
            return left.substr(0, i);
        }
    }
    return left.substr(0, len);
}

string solve(vector<string>& strs, int l, int r) {
    if (l == r) return strs[l];

    int mid = (l + r) / 2;

    string left = solve(strs, l, mid);
    string right = solve(strs, mid + 1, r);

    return commonPrefix(left, right);
}

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    return solve(strs, 0, strs.size() - 1);
}
int main() {
    vector<string> strs = {"flower", "flow", "flight", "flask"};
    cout << longestCommonPrefix(strs);
    return 0;
}