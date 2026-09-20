#include<bits/stdc++.h>
using namespace std;

void reverse(string &s) {
    int end = s.size() - 1;
    for(int i = 0;i<s.size()/2;i++) {
        swap(s[i], s[end--]);
    }
}

string copyString(string s) {
    string ans(s.size(), ' ');
    for(int i=0;i<s.size();i++) {
        ans[i] = s[i];
    }
    return ans;
}



int main() {
    string s = "Priyanshu";
    string k = "Keshri";
    // reverse(s);
    // for(int i=0;i<s.size();i++) {
    //     cout << s[i];
    // }
    // string ans = copyString(s);
    // for(int i=0;i<ans.size();i++) {
    //     cout << ans[i];
    // }
    cout << s+k;
    return 0;
}