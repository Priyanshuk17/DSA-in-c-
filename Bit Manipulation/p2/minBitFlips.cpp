#include<bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal) {
    int n = start ^ goal;
    int cnt = 0;
    for(int i = 0;i<31;i++) {
        if(n & (1<<i))
            cnt++;
    }
    return cnt;
}

int main() {
    int start = 10;
    int goal = 7;
    int ans = minBitFlips(start, goal);
    cout << ans;
    return 0;
}