#include<bits/stdc++.h>
using namespace std;


string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();
    if(m>n) return "";
    vector<int> hash(256, 0);
    // store frequency of characters t
    for(int i = 0;i<m;i++) {
        hash[t[i]]++;
    }

    int l = 0, r = 0;
    int count = 0;
    int minLen = INT_MAX;
    int start = -1;

    while(r < n) {
        // include current character
        if(hash[s[r]] > 0) 
            count++;
        hash[s[r]]--;
        // when all characters matched
        while(count == m) {
            if((r - l + 1) < minLen) {
                minLen = r - l + 1;
                start = l;
            }
            // remove left character
            hash[s[l]]++;
            if(hash[s[l]] > 0)
                count--;
            l++;
        }
        r++;
    }
    if(start == -1) return "";
    return s.substr(start, minLen);
}

int main() {
    string s = "adobecodebanc";
    string t = "abc";

    string ans = minWindow(s, t);
    cout << ans;

    return 0;
}