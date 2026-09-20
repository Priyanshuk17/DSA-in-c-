#include<bits/stdc++.h>
using namespace std;

string capitalizeFirstAndLast(string &s) {
    int n = s.size();
    for(int i=0;i<n;i++) {
        if(i == 0 || s[i-1] == ' ') {
            s[i] = toupper(s[i]);
        }
        if((i==n-1 || s[i + 1] == ' ') && isalpha(s[i])) {
            s[i] = toupper(s[i]);
        }
    }
    return s;
}
string capitalizeFirstAndLast(string &s) {
    int n = s.size();
    for(int i=0;i<n;i++) {
        if(i == 0 || s[i-1] == ' ') {
            s[i] = toupper(s[i]);
        }
        if((i == n-1 || s[i+1] == ' ' || isalpha(s[i]))) {
            s[i] = toupper(s[i]);
        }
    }
    return s;
}

int main() {
    string s = "take you forward";
    cout << capitalizeFirstAndLast(s);
    return 0;
}