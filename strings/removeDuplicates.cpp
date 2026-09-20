#include<bits/stdc++.h>
using namespace std;

// TC -> O(n) SC -> O(n)
string removeDuplicates(string &s) {
    unordered_map<char, bool> visited;
    string res;
    for(char ch : s) {
        if(!visited[ch]) {
            res += ch;
            visited[ch] = true;
        }
    }
    return res;
}

// TC -> O(n) SC-> O(1)
string removeDuplicates(string &s) {
    vector<int> freq(256, 0);
    string res;
    for (char ch : s) {
        if (freq[ch] == 0) {
            res += ch;
            freq[ch] = 1;
        }
    }
    return res;
}

int main() {
    string s;
    getline(cin, s);
    string res = removeDuplicates(s);
    cout << res;

    return 0;
}