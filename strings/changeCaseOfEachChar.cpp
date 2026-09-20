#include<bits/stdc++.h>
using namespace std;

void change(string &s) {
    int n = s.length();
    for(int i=0;i<n;i++) {
        int ascii = (int)s[i];
        if(ascii >= 65 && ascii <= 90) {
            s[i] = ((char) (ascii + 32));
        }
        else if(ascii >= 97 && ascii <= 122) {
            s[i] = ((char) (ascii - 32));
        }
    }
    cout << "After changing:- " << s;
}

int main() {
    string s;
    getline(cin, s);
    change(s);
    return 0;
}