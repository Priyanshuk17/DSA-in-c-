#include<bits/stdc++.h>
using namespace std;

// bool subset(vector<int> &a, vector<int> &b) {
//     int n = a.size();
//     int m = b.size();
//     for(int i=0;i<m;i++) {
//         bool found = false;
//         for(int j=0;j<n;j++) {
//             if(b[i] == a[j]){
//                 found = true;
//                 break;
//             }   
//         }
//         if(!found) {
//             return false;
//         }
//     }
//     return true;
// }
int sum(vector<int> &nums) {
    int n = nums.size();
    int totalSum = 0;
    for(int i=0;i<n;i++) {
        totalSum += nums[i];
    }
    int leftSum = 0;
    for(int i=0;i<n;i++) {
        totalSum -= nums[i];
        if(totalSum == leftSum) {
            return i;
        }
        else {
            leftSum += nums[i];
        }
    }
    return -1;
}

int main() {
    vector<int> a = {1, 1, 1, 1};
    // vector<int> b = {1, 2, 3};
    int res = sum(a);
    cout << res;
    return 0;
}