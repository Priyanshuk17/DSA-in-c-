#include<bits/stdc++.h>
using namespace std;

string solve(string &str) {
    int n = str.size();
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-1; j++) {
            if(str[j] > str[j+1]) {
                swap(str[j], str[j+1]);
            }
        }
    }
    return str;
}

int main() {
    string str = "zxcbg";
    cout << "Given string: " << "\n";
    cout << str << "\n";
    cout << "After sorting: " << "\n";
    cout << solve(str) << "\n";
    return 0;
}