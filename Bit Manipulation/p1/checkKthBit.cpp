#include<bits/stdc++.h>
using namespace std;

bool checkKthBit(int n, int k) {
    if((n & (1 << k)) != 0) 
        return true;
    else 
        return false;
}


int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    cout << checkKthBit(n, k);

    return 0;
}