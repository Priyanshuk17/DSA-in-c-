#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &arr, int N) {
    int xor1 = 0,xor2 = 0;
    int n = N-1;
    for(int i = 0;i<n;i++) {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
}

// Brute force method
// int missingNumber(vector<int> &arr, int N) {
//     for(int i = 1;i<N;i++) {
//         int flag = 0;
//         for(int j = 0;j<N;j++) {
//             if(arr[j]==i) {
//                 flag = 1;
//                 break;
//             }
//         }
//         if(flag == 0)
//             return i;
//     }
// }

//Better Approach
// Answer nhi aa rha h 
// lekin approach shi h ek baar recheck krna hoga
// int missingNumber(vector<int> &arr, int N) {
//     vector<int> hash(N-1) = {0};
//     for(int i=0;i<N;i++) {
//         hash[arr[i]] = 1;
//     }
//     for(int i=1;i<N;i++) {
//         if(hash[i]==0){
//             return i;
//         }
//     }
// }

int main() {
    int N;
    cout << "Enter numbers of elements of first array: "<<endl;
    cin >> N;

    vector<int> arr(N-1);
    cout << "Enter " << N-1 << " elements: " << endl;
    for(int i=0;i<N-1;i++) {
        cin >> arr[i];
    }
   
    cout << missingNumber(arr, N) << endl;
    return 0;
}