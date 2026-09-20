#include<bits/stdc++.h>
using namespace std;


// string removeChar(string &s1, string &s2) {
//     string res = "";
//     for(int i=0;i<s1.length();i++) {
//         bool found = false;
//         for(int j=0;j<s2.length();j++) {
//             if(s1[i] == s2[j]) {
//                 found = true;
//                 break;
//             }
//         }
//         if(!found) {
//             res += s1[i];
//         }
//     }
//     return res;
// }

string removeChar(string &s1, string &s2) {
    unordered_map<char, bool> removeMap;

    string res = "";
    for(char ch : s2) {
        removeMap[ch] = true;
    }
    for(char ch : s1) {
        if(removeMap.find(ch) == removeMap.end()) {
            res += ch;
        }
    }
    return res;
}

int main() {
    string s1 = "abcdefgz";
    string s2 = "efgz";
    string res = removeChar(s1, s2);
    cout << res;

    return 0;
}