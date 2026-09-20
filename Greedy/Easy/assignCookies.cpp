#include<bits/stdc++.h>
using namespace std;

int assignCookies(vector<int> &g, vector<int> &s) {
    int n = g.size();
    int m = s.size();
    int l = 0;
    int r = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    while(l<m && r<n) {
        if(g[r] <= s[l]) {
            r++;
        }
        l++;
    }
    return r;
}

int main() {
    vector<int> g = {1, 5, 3, 3, 4};
    vector<int> s = {4, 2, 1, 2, 1, 3};
    int res = assignCookies(g, s);
    cout << res;
    return 0;
}