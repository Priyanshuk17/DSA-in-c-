#include<bits/stdc++.h>
using namespace std;

bool checkAnagrams(string &s1, string &s2) {
    if(s1.length() != s2.length()) {
        return false;
    }
    for(char &c : s1)
        c = tolower(c);
    for(char &c : s2)
        c = tolower(c);
    int freq[26] = {0};
    for(int i=0;i<s1.size();i++) {
        freq[s1[i] - 'a']++;
    }
    for(int i=0;i<s2.size();i++) {
        freq[s2[i] - 'a']--;
    }
    for(int i=0;i<26;i++) {
        if(freq[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s1 = "ABC";
    string s2 = "BAC";
    int res = checkAnagrams(s1, s2);
    cout << res;

    return 0;
}