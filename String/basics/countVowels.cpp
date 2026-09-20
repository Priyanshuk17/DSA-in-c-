#include<bits/stdc++.h>
using namespace std;

int countVowels(string s) {
    int cnt = 0;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'|| s[i]=='A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    string s = "aeiou";
    int ans = countVowels(s);
    cout << ans;

    return 0;
}