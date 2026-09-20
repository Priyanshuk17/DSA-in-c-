#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int p = 1;
    for(auto it : s) {
        p *= (it -'0');
    }
    cout << p;
}