#include<bits/stdc++.h>
using namespace std;

// int findMaxConsecutive(vector<int> &arr) {
//     int maxi = 1;
//     int cnt = 1;
//     for(int i=0;i<arr.size()-1;i++) {
//         if(arr[i] == arr[i+1]) {
//             cnt++;
//         } else {
//             cnt = 1;
//         }
//         maxi = max(maxi, cnt);
//     }
//     return maxi;
// }

int findMaxProfit(vector<int> &arr) {
    int mini = arr[0];
    int maxProfit = 0;
    for(int i=0;i<arr.size();i++) {
        int cost = arr[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, arr[i]);
    }
    return maxProfit;
}

int main () {
    vector<int> arr = {7, 10, 1, 3, 6, 9, 2};
    int res = findMaxProfit(arr);
    cout << res;
    return 0;
}