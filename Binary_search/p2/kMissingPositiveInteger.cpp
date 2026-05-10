#include<bits/stdc++.h>
using namespace std;

int findKthPosition(vector<int> &arr, int k) {
    int n = arr.size();
    int low = 0;
    int high = n -1;
    while(low<=high) {
        int mid = (low + high) / 2;
        int missing = arr[mid] - (mid + 1);
        if(missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return (low + k);
}
// DERIVATION we have to make a formula
// if given input array is [4, 7, 9] and k = 3;
// then your low and high pointing at before 0th index so you cannot say thar arr[high] + more
// missing formula is arr[high] - (high + 1)
// more formula is (k - missing) 
// so arr[high] + more = 
// arr[high] + (k - missing) 
// arr[high] + (k - (arr[high] - (high + 1)))
// arr[high] + (k - arr[high] + (high + 1))
// arr[high] + k - arr[high] + high + 1
// k + high + 1 we have to return this or high + 1 = low so we can also write it as low + k

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    int ans = findKthPositive(arr, k);
    cout << ans;
    return 0;
}
`