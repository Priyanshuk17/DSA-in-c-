#include<bits/stdc++.h>
using namespace std;

// string func(string s, string t) {
//     vector<int> hash(256, 0);
//     int cnt = 0;
//     int n = s.size();
//     int m = t.size();
//     int l = 0;
//     int r = 0;
//     int minLen = INT_MAX;
//     int sInd = -1;
//     for(int i=0;i<m;i++) {
//         hash[t[i]]++;
//     }
//     while(r<s.size()) {
//         if(hash[s[r]] > 0) 
//             cnt++;
//         hash[s[r]]--;
    
//         while(cnt == m) {
//             if((r-l+1) < minLen) {
//                 minLen = r-l+1;
//                 sInd = l;
//             }
//             hash[s[l]]++;
//             if(hash[s[l]] > 0)
//                 cnt--;
//             l++;
//         }
//         r++;
//     }
//     return sInd==-1 ? "" : s.substr(sInd, minLen);
// }

string func(string s, string t) {
    int minLen = INT_MAX;
    int sInd = -1;
    for(int i=0;i<s.size();i++) {
        int cnt = 0;
        vector<int> hash(256, 0);
        for(int j=0;j<t.size();j++) hash[t[j]]++;
        for(int j=i;j<s.size();j++) {
            if(hash[s[j]] > 0) cnt++;
            hash[s[j]]--;
            if(cnt == t.size()){
                if((j-i+1) < minLen) {
                    minLen = j-i+1;
                    sInd = i;
                    break;
                }
            }
        }
    }
    return sInd==-1 ? "" : s.substr(sInd, minLen);
}

int main() {
    string s = "adobecodebanc";
    string t = "abc";

    string ans = func(s, t);
    cout << ans;

    return 0;
}