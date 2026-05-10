#include<bits/stdc++.h>
using namespace std;

int floor(vector<int> &arr, int x) {
    int n = arr.size();
    int ans = -1;
    int low = 0;
    int high = n-1;
    while(low<=high) {
        int mid = (low + high) / 2;
        if(arr[mid] <= x) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int ceil(vector<int> &arr, int x) {
    int n = arr.size();
    int ans = -1;
    int low = 0;
    int high = n-1;
    while(low<=high) {
        int mid = (low + high) / 2;
        if(arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 6, 6};
    int ans1 = floor(arr, 6);
    int ans2 = ceil(arr, 6);

    cout << ans1 << " " << ans2;

    return 0;
}