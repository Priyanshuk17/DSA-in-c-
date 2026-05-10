#include<bits/stdc++.h>
using namespace std;

int hashh(char c, string s) {
    int cnt = 0;
    for(int i=0;i<s.size();i++) {
        if(s[i]==c)
            cnt++;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char c = 'a';
    cout << hashh(c, s);
    return 0;
}