#include<bits/stdc++.h>

using namespace std;
// Brute force code
// void leftRotate(int arr[], int n, int d) {
//     This is using extra space d
//     TC -> O(n+d)
//     SC -> O(d)
//     d = d % n;
//     int temp[d];
//     for(int i=0;i<d;i++) {
//         temp[i] = arr[i];
//     }
//     for(int i=d;i<n;i++) {
//         arr[i-d] = arr[i];
//     }
//     for(int i=n-d;i<n;i++) {
//         arr[i] = temp[i-(n-d)];
//     }
// }
// If for optimising there is slight increase in
// time complexity to O(2n) but space complexity
// will reduced to O(1)
// void leftRotate(vector<int> &arr,int n, int d) {
//     d = d % n;
//     vector<int> temp(d);
//     for(int i=0;i<d;i++) {
//         temp[i] = arr[i];
//     }
//     for(int i=d;i<n;i++) {
//         arr[i-d] = arr[i];
//     }
//     for(int i=n-d;i<n;i++){
//         arr[i] = temp[i-(n-d)];
//     }
// }

//Optimal approach
// void leftRotate(vector<int>& arr, int n, int d) {
//     reverse(arr.begin(), arr.begin()+d);
//     reverse(arr.begin()+d, arr.begin()+n);
//     reverse(arr.begin(), arr.begin()+n);  
// }

// void leftRotate(vector<int>& arr, int n, int d) {
//     reverse(arr.begin(), arr.begin()+d);
//     reverse(arr.begin() + d,arr.begin() + n);
//     reverse(arr.begin(), arr.end());
// }
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int d;
    cin >> d;

    d = d % n;

    leftRotate(arr, n, d);
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// If your languge does'nt provide reverse 
// Function then it is quite easier
// void Reverse(int arr[], int start, int end) {
//     while(start<=end) {
//         int temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;
//         start++;
//         end--;
//     }
// }