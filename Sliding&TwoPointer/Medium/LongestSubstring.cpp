#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> hash(256, -1); // stores last index of charecters

    int l = 0;
    int maxLen = 0;

    for(int r = 0;r<s.size();r++) {
        // if character already seen and inside window
        if(hash[s[r]] >= l) {
            l = hash[s[r]] + 1;
        }

        // update last seen index
        hash[s[r]] = r;

        // calculate window length
        int len = r - l + 1;
        maxLen = max(len, maxLen);
    }
    return maxLen;
}

int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    int n = s.size();
    for(int i = 0;i<n;i++) {
        unordered_map<char, int> mpp;
        for(int j = i;j<n;j++) {
            if(mpp[s[j]] == 1) break;
            int len = j - i + 1;
            maxLen = max(len, maxLen);
            mpp[s[j]] = 1;
        }
    }
    return maxLen;
}

int main() { 
    string s = "cadbzabc";
    cout << lengthOfLongestSubstring(s);

    return 0;
}