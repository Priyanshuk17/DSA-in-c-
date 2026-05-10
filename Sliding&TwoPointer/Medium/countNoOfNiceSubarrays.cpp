#include<bits/stdc++.h>
using namespace std;

int countSumLessThanK(vector<int> &arr, int k) {
    int l=0,r=0;
    int sum = 0;
    int cnt = 0;
    while(r<arr.size()) {
        sum += (arr[r] % 2);
        while(sum > k) {
            sum = sum - (arr[l] % 2);
            l++;
        }
        cnt = cnt + (r - l + 1);
        r++;
    }
    return cnt;
}

int noOfNiceSub(vector<int> &arr, int k) {
    int res1 = countSumLessThanK(arr, k);
    int res2 = countSumLessThanK(arr, k - 1);
    return res1 - res2;
}

int main() {
    vector<int> arr = {1, 1, 2, 1, 1};
    int k = 3;
    int ans = noOfNiceSub(arr, k);
    cout << ans;
    return 0;
}