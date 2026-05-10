#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int k) {
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == k) return mid; 

        if(arr[low] <= arr[mid]) {
            if(arr[low] <= k && k <= arr[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else {
            if(arr[mid] <= k && k <= arr[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {3, 4, 5, 6, 1, 2};
    int n = arr.size();
    int k = 3;     
    int ans = search(arr, n, k);
    cout << "Returning index" << ans;
    return 0;
}