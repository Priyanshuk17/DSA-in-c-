#include<bits/stdc++.h>
using namespace std;

// int numberOfSetBits(int n) {
//     int cnt = 0;
//     while(n!=0) {
//         n = (n & (n-1));
//         cnt++;
//     }
//     return cnt;
// }

int numberOfSetBits(int n) {
    int cnt = 0;
    while(n > 1) {
        if(n % 2 == 1) cnt++;
        n = n / 2;
    }
    if(n == 1) cnt+=1;
    return cnt;
}

int main() {
    int n;
    cin >> n;
    cout << numberOfSetBits(n);

    return 0;
}