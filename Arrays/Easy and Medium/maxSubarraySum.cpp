#include<bits/stdc++.h>
using namespace std;

// Optimal approach
// Kadane's algorithm
long long maxSubarraySum(int arr[], int n) {
    long long sum = 0, maxi = LONG_MIN;
    for(int i = 0;i<n;i++) {
        sum += arr[i];
        if(sum > maxi) {
            maxi = sum;
        }
        if(sum < 0) {
            sum = 0;
        }
    }
    if(maxi < 0) {
        maxi = 0;
    }
    return maxi;
}

// better approach
// long long maxSubarraySum(int arr[], int n) {
//     long long maxi = LONG_MIN;
//     for(int i = 0;i < n;i++) {
//         long long sum = 0;
//         for(int j=i;j<n;j++) {
//             sum += arr[j];
//             maxi = max(sum, maxi);
//         }
//     }
//     return maxi;
// }

int main() {
    int n;
    cout << "Enter numbers of elements in an array: "<<endl;
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: " << endl;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
   
    cout << maxSubarraySum(arr, n);
    
    return 0;
}