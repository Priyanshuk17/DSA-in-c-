#include<bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    // Edge case: overflow
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    // Determine sign
    bool sign = (dividend >= 0) == (divisor >= 0);

    long long n = labs(dividend);
    long long d = labs(divisor);

    long long quotient = 0;

    while (n >= d) {
        int cnt = 0;
        while (n >= (d << (cnt + 1))) {
            cnt++;
        }
        quotient += (1LL << cnt);
        n -= (d << cnt);
    }
    return sign ? quotient : -quotient;
}


int main() {
    int dividend;
    cin >> dividend;
    int divisor;
    cin >> divisor;
    int res = divide(dividend, divisor);
    cout << res;
    return 0;
}