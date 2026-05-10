#include<bits/stdc++.h>
using namespace std;

int setKthBit(int n, int k) {
    n = (n | (1 << k));
    return n;
        
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    cout << setKthBit(n, k);
    return 0;
}