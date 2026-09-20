#include<bits/stdc++.h>
using namespace std;

int countChar(string s) {
    int length = 0;
    while(s[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    string s = "Priyanshu";
    int res = countChar(s);
    cout << res;

    return 0;
}