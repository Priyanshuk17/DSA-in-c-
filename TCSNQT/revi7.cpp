#include<bits/stdc++.h>
using namespace std;

// int func(vector<int> &arr) {
//     int n = arr.size();
//     for(int i=0;i<n;i++) {
//         int cnt = 1;
//         for(int j=i+1;j<n;j++) {
//             if(arr[i]==arr[j]) {
//                 cnt++;
//             }
//         }
//         if(cnt>(n/2)) {
//             return arr[i];
//         }
//     }
//     return -1;
// }

int func(vector<int> &arr) {
    int n = arr.size();
    int cnt = 0;
    int el;
    for(int i=0;i<n;i++) {
        if(cnt==0) {
            cnt = 1;
            el = arr[i];
        }
        else if(arr[i]==el) {
            cnt++;
        }
        else {
            cnt--;
        }
    }
    int cnt1 = 0;
    for(int i=0;i<n;i++) {
        if(arr[i]==el) {
            cnt1++;
        }
    }
    if(cnt1>n/2) {
        return el;
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 1, 2, 5, 3, 3, 1};
    int ans = func(arr);
    cout << ans;
    return 0;
}