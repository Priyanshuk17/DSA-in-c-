#include<bits/stdc++.h>
using namespace std;

int subarrayWithXorK(vector<int> &arr, int k) {
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++; // [0, 1] ke liye zaroori hai
    int cnt = 0;
    for(int i = 0;i<arr.size();i++) {
        xr = xr ^ arr[i];
        // k
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int ans = subarrayWithXorK(arr, 6);
    cout << ans;

    return 0;
}