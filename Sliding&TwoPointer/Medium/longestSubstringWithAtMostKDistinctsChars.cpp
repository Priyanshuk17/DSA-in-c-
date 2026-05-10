#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k) {
    int l = 0;
    int maxLen = 0;
    unordered_map<char, int> mpp;
    int r = 0;
    while(r<s.size()) {
        mpp[s[r] - 'a']++;
        if(mpp.size()>k) {
            mpp[s[l] - 'a']--;
            if(mpp[s[l] - 'a']==0) {
                mpp.erase(mpp[s[l] - 'a']);
            }
            l++;
        }
        if(mpp.size()<=k) {
            maxLen = max(maxLen, r-l+1);
        }
        r++;
    }
    return maxLen;
}

int main() {
    string s = "aaaabbbbcddd";
    int ans = longestSubstring(s, 2);
    cout << ans;
    return 0;
}