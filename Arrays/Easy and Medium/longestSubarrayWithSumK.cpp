#include<bits/stdc++.h>
using namespace std;


// It is better of positives elements in array
// But But But it is optimal for positive as well 
// as negative elements in an array
// int longestSubarrayWithSumK(vector<int> arr, long long k) {
//     map<long long, int> preSumMap;
//     long long sum = 0;
//     int maxLen = 0;
//     for(int i=0;i<arr.size();i++) {
//         sum += arr[i];
//         if(sum == k) {
//             maxLen = max(maxLen, i+1);
//         }
//         long long rem = sum - k;
//         if(preSumMap.find(rem) != preSumMap.end()) {
//             int len = i-preSumMap[rem];
//             maxLen = max(maxLen, len);
//         }
//         if(preSumMap.find(sum) == preSumMap.end()) {
//             preSumMap[sum] = i;
//         }
//         preSumMap[sum] = i;
//     }
//     return maxLen;
// }

int longestSubarrayWithSumK(vector<int> arr, long long k) {
    int left = 0;
    int right = 0;
    long long sum = arr[0];
    int maxLen = 0;
    int n = arr.size();
    while(right < n) {
        while(left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }
        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n) sum += arr[right];
    }
    return maxLen;
    
}

int main() {
    int n;
    cout << "Enter numbers of elements in an array: "<<endl;
    cin >> n;

    int k;
    cout << "The longest subarray we find with sum of " << endl;
    cin >> k;
    cout << "The longest subarray we find with sum of " << k << endl;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: " << endl;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
   
    cout << longestSubarrayWithSumK(arr, k) << endl;
    return 0;
}