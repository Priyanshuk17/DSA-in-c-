#include<bits/stdc++.h>
using namespace std;

vector<int> superiorElement(vector<int>&a) {
    vector<int> ans;
    int maxi = INT_MIN;
    int n = a.size();
    // O(n)
    for(int i=n-1;i>=0;i--) {
        if(a[i] > maxi) {
            ans.push_back(a[i]);
        }
        // keep track of right max
        maxi = max(maxi, a[i]);
    }
    // O(nlogn)
    sort(ans.begin(), ans.end());
    return ans;
}

// Brute force method
// vector<int> superiorElement(vector<int>&a) {
//     int n = a.size();
//     vector<int> ans;
//     for(int i=0;i<n;i++) {
//         bool leaders = true;
//         for(int j=i+1;i<n;i++) {
//             if(a[j] > a[i]) {
//                 leaders = false;
//                 break;
//             }
//         } 
//         if(leaders == true)
//             ans.push_back(a[i]);
//     }
//     return ans;
// }


int main() {
    vector<int> arr = {11, 22, 10, 5, 33};

    vector<int> ans = superiorElement(arr);
    for(auto it : ans ) {
        cout << it << " ";
    }
    return 0;
}