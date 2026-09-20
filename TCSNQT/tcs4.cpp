#include<bits/stdc++.h>
using namespace std;

int findInSubset(string &s) {
    int maxx = 0;
    int cnt = 0;
    int n = s.size();
    for(int i=0;i<n;i++) {
        if(i%n == 0) {
            maxx = max(maxx, cnt);
            cnt = 0;
        }
        if(s[i] == 'a')
            cnt++;
    }
    maxx = max(maxx, cnt);
    return maxx;
}

int main() {
    string s = "bbbaaababa";
    int res = findInSubset(s);
    cout << res;
    return 0;
}