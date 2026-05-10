#include<bits/stdc++.h>
using namespace std;

int isSorted(int n, int arr[]) {
    for(int i=1;i<n;i++) {
        if(arr[i] >= arr[i-1]) {

        }
        else {
            return false;
        }
    }
    return true;
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
    cout << isSorted(n, arr);

    return 0;
}