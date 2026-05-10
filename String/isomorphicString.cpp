#include<bits/stdc++.h>
using namespace std;


// bool isomorphicString(string s, string t) {
//     if(s.size()!=t.size()) return false;
//     int n = s.size();

//     for(int i=0;i<n;i++) {
//         char ch1 = s[i];
//         char ch2 = t[i];
//         for(int j=0;j<n;j++) {
//             if(s[j]==ch1) {
//                 if(t[j]!=ch2){
//                     return false;
//                 }
//             }
//             if(t[j]==ch2){
//                 if(s[j]!=ch1){
//                     return false;
//                 }
//             }
//         }
//     }
//     return true;
// }
bool isomorphicString(string s, string t) {
    int n = s.size();
    int m = t.size();
    if(n!=m) return false;
    unordered_map<char, char> mapST;
    unordered_map<char, char> mapTS;
    for(int i=0;i<n;i++) {
        char ch1 = s[i];
        char ch2 = t[i];

        // check s -> t mapping
        if(mapST.count(ch1)) {
            if(mapST[ch1]!= ch2) {
                return false;
            }
        }
        else if(mapTS.count(ch2)) {
            if(mapTS[ch2]!=ch1) {
                return false;
            }
        }
        else {
            mapST[ch1] = ch2;
            mapTS[ch2] = ch1;
        }
    }
    return true;
}

int main() {
    string s = "paper";
    string t = "title";

    cout << isomorphicString(s, t);
    return 0;
}