#include<bits/stdc++.h>
using namespace std;

int findPainter(vector<int> &arr, int n) {
    int painter = 1;
    long long m = 0;
    for(int i = 0;i < arr.size(); i++) {
        if(arr[i] + m <= n) {
            m += arr[i];
        }
        else {
            painter+=1;
            m = arr[i];
        }
    }
    return painter;
}


int painters(vector<int> &arr ,int k) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low<=high) {
        int mid = (low + high) / 2;
        int noOfpainter = findPainter(arr, mid);
        if(noOfpainter > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}


int main() {
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;
    int ans = painters(arr, k);
    cout << ans;
    return 0;
}