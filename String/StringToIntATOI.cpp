#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int i = 0;
    int n = s.size();
    while(i<n && s[i] == ' ') i++;

    int sign = 1;
    if(s[i] == '-' ) {
        sign = -1;
        i++;
    } else if(s[i] == '+') {
        i++;
    }
    long long num = 0;
    while(i < n && isdigit(s[i])) {
        int digit = s[i] - '0';
        // 🔥 overflow check BEFORE multiplying
        if(num > (LONG_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        num = num * 10 + digit;
        i++;
    }
    num = num * sign;
    if(num > INT_MAX) return INT_MAX;
    if(num < INT_MIN) return INT_MIN;

    return num;
}

int main() {
    string s = "-042";
    cout << myAtoi(s);
    return 0;
}