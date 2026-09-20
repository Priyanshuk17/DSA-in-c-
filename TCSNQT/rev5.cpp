#include<bits/stdc++.h>
using namespace std;

// vector<int> func(vector<int> &arr) {
//     int n = arr.size();
//     vector<int> nz;
//     for(int i=0;i<n;i++) {
//         if(arr[i]!=0) {
//             nz.push_back(arr[i]);
//         }
//     }
//     for(int i=nz.size();i<n;i++) {
//         nz.push_back(0);
//     }
//     return nz;
// }

void moveZeros(vector<int> &arr) {
    int n = arr.size();
    int nonZero = 0;
    for(int i=0;i<n;i++) {
        if(arr[i] != 0) {
            swap(arr[i], arr[nonZero]);
            nonZero++;
        }
    }
}

int main() {
    vector<int> arr = {1, 0, 0, 2, 3};
    moveZeros(arr);
    for(auto it : arr) {
        cout << it << " ";
    }
    return 0;
}