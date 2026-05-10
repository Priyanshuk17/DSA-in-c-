#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    double ans = 1.0;
    long long nn = n;
    if(n<0) nn = -1 * nn;
    while(nn) {
        if(nn%2) {
            ans = ans * x;
            nn = nn - 1;
        } else {9
            x = x * x;
            nn = nn / 2;
        }
    }
    if(n<0) ans = (double) (1.0) / (double) (ans);
    return ans;
}

int main () {
    double x = 5;
    int n = 2;
    double ans = myPow(x, n);
    cout << ans;
    return 0;
}