#include<bits/stdc++.h>
using namespace std;

// int xorr(int n) {
//     if(n%4==1) return 1;
//     else if(n%4==2) return n + 1;
//     else if(n%4==3) return 0;
//     else return n;
// }

int xorr(int n) {
    int ans = 0;
    for(int i=1;i<=n;i++) {
        ans ^= i;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int ans = xorr(n);
    cout << ans;
    return 0;
}