#include<bits/stdc++.h>
using namespace std;

// Better approach
// string twoSumRead(int n, vector<int> arr, int target) {
//     map<int, int> mpp;
//     for(int i=0;i<n;i++) {
//         int a = arr[i];
//         int more = target - a;
//         if(mpp.find(more) != mpp.end()) {
//             return "Yes";
//         }
//         mpp[a] = i;
//     }
//     return "No";
// }


// optimal approach
string twoSumRead(int n, vector<int> arr, int target) {
    int left = 0;
    int right = n - 1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == target) {
            return "Yes";
        }
        else if(sum<target) left++;
        else right--;
    }
    return "No";
}

// Better approach
// vector<int> twoSum(vector<int>& arr, int target) {
//     map<int,int> mpp;
//     int n = arr.size();
//     for(int i = 0;i<n;i++) {
//         int num = arr[i];
//         int more = target - num;
//         if(mpp.find(more) != mpp.end()) {
//             return {mpp[more], i};
//         }
//         mpp[num] = i;
//     }
//     return {-1, -1};
// }

vector<int> twoSum(vector<int> &arr, int target) {
    map<int, int> mpp;
    int n = arr.size();
    for(int i = 0; i < n ;i++) {
        int num = arr[i];
        int more = target - num;
        if(mpp.find(more) != mpp.end()) {
            return {mpp[more], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};
}
int main() {
    // int n;
    // cout << "Enter numbers of elements in an array: "<<endl;
    // cin >> n;

    // int target;
    // cout << "Your target is:- " << endl;
    // cin >> target;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: " << endl;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
   
    cout << twoSumRead(n, arr, target);
    // vector<int> read = twoSum(arr, target);

    // cout << "Read on index:\n";
    // for(int num: read) {
    //     cout << num << " "; 
    // }
    // cout << endl;
    
    return 0;
}