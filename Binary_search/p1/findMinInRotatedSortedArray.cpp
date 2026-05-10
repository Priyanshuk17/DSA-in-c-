#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while(low<=high) {
        int mid = (low + high) / 2;
        // search space is already sorted
        // then always arr[low] is will be smaller
        // in that search space
        if(arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }
        if(arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else {
            high = mid - 1;
            ans = min(ans, arr[mid]);
        }
    }
    return ans;
}

int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while(low <= high) {
        int mid = (low + high) / 2;

        // 🔥 handle duplicates (no info case)
        if(arr[low] == arr[mid] && arr[mid] == arr[high]) {
            ans = min(ans, arr[low]);
            low++;
            high--;
            continue;
        }

        // left half sorted
        if(arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // right half sorted
        else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr= {2, 2, 2, 2, 0, 2, 2};
    int ans = findMin(arr);
    cout << ans;
    return 0;
}