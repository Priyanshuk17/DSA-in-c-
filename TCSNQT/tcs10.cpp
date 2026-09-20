#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string &s) {
    bool seen[26] = {false};
    string res = "";
    for(char ch : s) {
        if(!seen[ch - 'a']) {
            seen[ch - 'a'] = true;
            res += ch;
        }
    }
    return res;
}

int main() {
    string s = "google";
    string res = removeDuplicates(s);
    cout << res;
    return 0;
}