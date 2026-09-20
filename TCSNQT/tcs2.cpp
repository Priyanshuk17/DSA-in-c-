#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &arr) {
    int n = arr.size();
    int cnt = 1;
    int comp = arr[0];
    for(int i=1;i<n;i++) {
        if(arr[i] > comp) {
            cnt++;
        }
    }
    return cnt;
}


int main() {
    vector<int> arr = {3, 4, 5, 8, 9};
    int res = func(arr);
    cout << res;
    return 0;
}