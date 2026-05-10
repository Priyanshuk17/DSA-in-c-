#include<bits/stdc++.h>
using namespace std;

// optimal
int secondLargest(int arr[], int n) {
    int largest = arr[0];
    int slargest = -1;
    for(int i=1;i<n;i++) {
        if(arr[i] > largest) {
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > slargest) {
            slargest = arr[i];
        }
    }
    return slargest;
}

// brute
// int secondLargest(int arr[], int n) {
//     sort(arr, arr+n);
//     int largest = arr[n-1];
//     int second;
//     for(int i=n-2;i>=0;i--) {
//         if(arr[i]!=largest) {
//             second = arr[i];
//             break;
//         }
//     }
//     return second;
// }

int secondSmallest(int arr[], int n) {
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for(int i=0;i<n;i++) {
        if(arr[i] < smallest) {
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] != smallest && arr[i] < ssmallest) {
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}
 
bool checkSorted(int arr[], int n) {
    for(int i=1;i<n;i++) {
        if(arr[i] >= arr[i-1]) {

        }
        else return false;
    }
    return true;
}

// int secondOrderElements(int arr[], int n) {
//     int slargest = secondLargest(arr, n);
//     int ssmallest = secondSmallest(arr, n);
//     return {slargest, ssmallest};
// }

int main() {
    int n;
    cout << "Enter the size of array \n";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements \n";
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    cout << "Second largest:- " << secondLargest(arr, n);
    // cout << "\nSecond smallest:- " << secondSmallest(arr, n);

    return 0;
}