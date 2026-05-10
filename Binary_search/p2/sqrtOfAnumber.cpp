#include<bits/stdc++.h>
using namespace std;

// int floorSqrt(int n) {
//     int low = 1, high = n;
//     while(low <= high) {
//         long long mid = (low + high) / 2;
//         long long val = (mid * mid);
//         if(val <= n) {
//             low = mid + 1;
//         }
//         else {
//             high = mid - 1;
//         }
//     }
//     return high;
// }

int findSqrt(int n) {
    int low = 0;
    int high = n;
    int ans = 1;
    while(low<=high) {
        int mid = (low + high) / 2;
        if(mid * mid <= n) {
            ans = mid;
            low = mid + 1;
        } 
        else { 
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n = 25;
    int ans = findSqrt(n);
    cout << ans;
    return 0;
}