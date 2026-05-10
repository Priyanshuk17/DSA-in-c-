#include<bits/stdc++.h>
using namespace std;

// brute force code
// long double minimiseMaxDistance(vector<int> &arr, int k) {
//     int n = arr.size();
//     vector<int> howMany(n-1, 0);
//     for(int gasStation=1;gasStation<=k;gasStation++) {
//         long double maxSection = -1;
//         int maxInd = -1;
//         for(int i=0;i<n-1;i++) {
//             long double diff = arr[i+1] - arr[i];
//             long double sectionLength = diff / (long double)(howMany[i] + 1);
//             if(sectionLength > maxSection) {
//                 maxSection = sectionLength;
//                 maxInd = i;
//             }
//         }
//         howMany[maxInd]++;
//     }
//     long double maxAns = -1;
//     for(int i = 0;i < n-1;i++) {
//         long double diff = (arr[i+1] - arr[i]);
//         long double sectionLength = diff / (long double)(howMany[i] + 1);
//         maxAns = max(maxAns, sectionLength);
//     }
//     return maxAns;
// }
// Better one
long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> howMany(n-1, 0);
    priority_queue<pair<long double, int>> pq;
    for(int i = 0;i<n-1;i++) {
        pq.push({arr[i+1] - arr[i], i});
    }
    for(int gasStation = 1; gasStation <= k; gasStation++) {
        auto tp = pq.top(); pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double iniDiff = arr[secInd - 1] - arr[secInd];
        long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }
    return pq.top().first;
}
int main() {
    vector<int> arr = {1, 13, 17, 23};
    int k = 5;
    int ans = minimiseMaxDistance(arr, k);
    cout << ans;
    return 0;
}