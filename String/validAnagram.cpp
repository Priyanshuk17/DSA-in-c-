#include<bits/stdc++.h>
using namespace std;


// brute force approach TLE maar gya leetcode me
// bool isAnagram(string s, string t) {
//     if(s.size() != t.size()) return false;

//     string temp = t;

//     for(int i=0;i<s.size();i++) {
//         bool found = false;

//         for(int j=0;j<s.size();j++) {
//             if(s[i] == temp[j]) {
//                 // mark it used
//                 temp[j] = '#';
//                 found = true;
//                 break;
//             }
//         }
//         if(!found) {
//             return false;
//         }
//     }
//     return true;
// }


// better approach TC -> O(n^2)
// bool isAnagram(string s, string t) {
//     if(s.size() != t.size()) return false;

//     sort(s.begin(),s.end());
//     sort(t.begin(),t.end());
//     if(s == t) {
//         return true;
//     }
//     return false;
// }

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;

    vector<int> freq(26, 0);
    for(int i=0;i<s.length();i++) {
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
    }
    // check all values are zero
    for(int count : freq) {
        if(count!=0) {
            return false;
        }
    }
    return true;
}
int main() {
    string s = "anagram";
    string t = "nagaram";

    cout << isAnagram(s, t);
    return 0;
}