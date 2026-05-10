#include<bits/stdc++.h>
using namespace std;

// int findRotation(vector<int> &arr) {
//     int low = 0, high = arr.size() - 1;
//     int ans = INT_MAX;
//     int index = -1;
//     while(low<=high) {
//         int mid = (low + high) / 2;
//         // search space is already sorted
//         // then always arr[low] is will be smaller
//         // in that search space
//         if(arr[low] <= arr[high]) {
//             if(arr[low] < ans) {
//                 index = low;
//                 ans = arr[low];
//             }
//             break;
//         }
//         if(arr[low] <= arr[mid]) {
//             if(arr[low] < ans) {
//                 index = low;
//                 ans = arr[low];
//             }
//             low = mid + 1;
//         }
//         else {
//             high = mid - 1;
//             if(arr[mid] < ans) {
//                 index = mid;
//                 ans = arr[mid];
//             }
//         }
//     }
//     return index;
// }

int singleElement(vector<int> &arr) {
    int n = arr.size();
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int low = 1;
    int high = n - 2;
    while(low <= high) {
        int mid = low  + (high - low) / 2;
        if(arr[mid] != arr[mid + 1] && arr[mid] != arr[mid-1]) {
            return arr[mid];
        }
        // left half 
        if((mid % 2 == 1 && arr[mid-1] == arr[mid]) || (mid % 2 == 0 && arr[mid] == arr[mid+1])) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    int ans = singleElement(arr);
    cout << ans;
    return 0;
}