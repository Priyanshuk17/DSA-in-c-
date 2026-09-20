#include<bits/stdc++.h>
using namespace std;

// int eqillibrium(vector<int> &arr) {
//     int n = arr.size();
//     for(int i=0;i<n;i++) {
//         int leftSum = 0;
//         int rightSum = 0;
//         for(int j=i-1;j>=0;j--) {
//             leftSum += arr[j];
//         }
//         for(int k=i+1;k<n;k++) {
//             rightSum += arr[k];
//         }
//         if(leftSum == rightSum) {
//             return i;
//         }
//     }
//     return -1;
// }

int eqillibrium(vector<int> &arr) {
    int n = arr.size();
    int totalSum = 0;
    for(int it : arr) {
        totalSum += it;
    }
    int leftSum = 0;
    for(int i=0;i<n;i++) {
        totalSum -= arr[i];
        if(totalSum == leftSum) {
            return i;
        }
        leftSum += arr[i];
    }
    return -1;
}

int main() {
    vector<int> arr = {3, 4, 8, -9, 20, 6};
    int ans = eqillibrium(arr);
    cout << ans;
    return 0;
}