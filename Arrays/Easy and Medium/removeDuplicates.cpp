#include<bits/stdc++.h>
using namespace std;

// Brute force approach me set ka use hoga
// Mtlb ki first khayal hame set stl func ka 
// use krna chahiye kyuki set me sirf ek element 
// ek hi baar rhta h
// TC->n+nlogn
// SC-> O(n) Brute force approach ka

// Optimal me two pointer ka use krenge
// TC->O(n)
// SC->O(1)
int removeDuplicates(int n, int arr[]) {
    int i=0;
    for(int j=1;j<n;j++) {
        if(arr[i] != arr[j]) {
            arr[i+1] = arr[j];
            i++;
        }
    }
    return (i+1);
}

// Brute force method
// int removeDuplicates(int n, int arr[]) {
//     set<int> st;
//     for(int i = 0;i<n;i++) {
//         st.insert(arr[i]);
//     }
//     int index = 0;
//     for(auto it : st) {
//         arr[index] = it;
//         index++;
//     }
//     return (index);
// }
// This will give size of array the array 
// In which we have storing only the elments
// Which appearing one time

int removeDuplicates(int arr[], int n) {
    set<int> st;
    for(int i=0;i<n;i++) {
        st.insert(arr[i]);
    }
    int index = 0;
    for(auto it ; st) {
        arr[index] = it;
        index++;
    }
    return (index);
}

int main() {
    int n;
    cout << "Enter the size of array \n";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements \n";
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    cout << removeDuplicates(n, arr);

    return 0;
}