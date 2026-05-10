#include<bits/stdc++.h>
using namespace std;


int toggleBits(int n, int l, int r) {
    for(int i = l; i <= r; i++) {
        n = n ^ (1 << (i - 1));
    }
    return n;
}


int main() {
    int n;
    cout << "Enter number you wants to" << endl;
    cin >> n;
    int l;
    cout << "Enter the range from" << endl;
    cin >> l;
    int r;
    cout << "Enter the range to" << endl;
    cin >> r;

    cout << toggleBits(n, l, r);
    return 0;
}