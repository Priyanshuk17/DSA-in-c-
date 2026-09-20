#include<bits/stdc++.h>
using namespace std;

// vector<int> func(vector<int> &arr) {
//     int n = arr.size();
//     vector<int> ans;
//     ans.push_back(arr[0]);
//     for(int i=1;i<n;i++) {
//         if(arr[i] == arr[i-1]) {
//             continue;
//         }
//         else {
//             ans.push_back(arr[i]);
//         }
//     }
//     return ans;
// }
vector<int> func(vector<int> &arr) {
    int n = arr.size();
    int i=0;
    for(int j=1;j<n;j++) {
        if(arr[j]!=arr[i]) {
            arr[i+1] = arr[j];
            i++;
        }
    }
    arr.resize(i+1);
    return arr;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 3, 4};
    vector<int> ans = func(arr);
    for(auto it : ans) {
        cout << it << " ";
    } 
    return 0;
}