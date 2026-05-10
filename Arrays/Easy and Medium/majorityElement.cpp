#include<bits/stdc++.h>
using namespace std;

// Better approach
// int majorityElement(vector<int>& arr) {
//     map<int, int> mpp;
//     for(int i=0;i<arr.size();i++) {
//         mpp[arr[i]]++;
//     }
//     for(auto it : mpp) {
//         if(it.second > (arr.size() / 2)) {
//             return it.first;
//         }
//     }
//     return -1;
// }

// Optimal approach
// int majorityElement(vector<int> arr) {
//     int cnt = 0;
//     int el;
//     for(int i = 0;i<arr.size();i++) {
//         if(cnt==0) {
//             cnt=1;
//             el = arr[i];
//         }
//         else if(arr[i] == el) {
//             cnt++;
//         }
//         else {
//             cnt--;
//         }
//     }
//     int cnt1 = 0;
//     for(int i = 0;i<arr.size();i++) {
//         if(arr[i] == el) cnt1++;
//     }
//     if(cnt1 > (arr.size() / 2)) {
//         return el;
//     }
//     return -1;
// }
int majorityElement(vector<int> arr) {
    int cnt = 0;
    int el;
    for(int i = 0;i<arr.size();i++) {
        if(cnt==0){
            cnt = 1;
            el = arr[i];
        }
        else if(arr[i] == el) {
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1 = 0;
    for(int i=0;i<arr.size();i++) {
        if(arr[i] == el) cnt1++;
    }
    if(cnt1 > (arr.size() / 2)) {
        return el;
    }
}
int main() {
    int n;
    cout << "Enter numbers of elements in an array: "<<endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: " << endl;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
   
    cout << majorityElement(arr);
    
    
    return 0;
}