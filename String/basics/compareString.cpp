#include<bits/stdc++.h>
using namespace std;

bool check(string s1, string s2)  {
    if(s1.size() != s2.size()) {
        return false;
    }
    for(int i=0;i<s1.size();i++) {
        if(s1[i]==s2[i]) {
            continue;
        }
        else {
            break;
            return false;
        }
    }
    return true;
}

int main() {
    string s1 = "Priyanshu";
    string s2 = "Priyanshu";
    int res = check(s1, s2);
    cout << res;
    return 0;
}