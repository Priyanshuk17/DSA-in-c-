#include<bits/stdc++.h>
using namespace std;

string changeEveryLetter(string &s) {
    string res = "";
    for (char ch : s) {
        if (ch == 'z')
            res += 'a';
        else if (ch == 'Z')
            res += 'A';
        else
            res += ch + 1;
    }
    return res;
}

int main() {
    string s;
    getline(cin, s);
    cout << changeEveryLetter(s);
    return 0;
}