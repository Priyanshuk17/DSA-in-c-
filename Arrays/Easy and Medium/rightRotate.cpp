#include<bits/stdc++.h>
using namespace std;


// // Brute force technique
// TC-> O(n+d)
// SC-> O(d)
// void rightRotate(int arr[], int n, int d) {
//     d = d % n;
//     int temp[d];
//     // step 1
//     for(int i=n-d;i<n;i++) {
//         temp[i-(n-d)] = arr[i];
//     }
//     // step 2
//     for(int i=n-d-1;i>=0;i--) {
//         arr[i+d] = arr[i];
//     }
//     // step 3
//     for(int i=0;i<d;i++) {
//         arr[i] = temp[i];
//     }
// }

void rightRotate(int arr[], int n, int d) {
    d = d % n;
    vector<int> temp;
    for(int i = 0;i<n-d;i++) {
        temp.push_back(arr[i]);
    }
    int j = n-d;
    for(int i = 0;i<d;i++) {
        arr[i] = arr[j];
        j++;
    }
    int k = 0;
    for(int i = d;i<n;i++) {
        arr[i]  = temp[k];
        k++;
    }

}

// Optimal approach
// TC->O(2n)
// SC->O(1) no extra space used
// void rightRotate(int arr[], int n, int d) {
//     if(n == 0) return;
//     d = d % n;

//     reverse(arr.begin()+n-d,arr.begin()+n);
//     reverse(arr.begin(), arr.begin()+n-d);
//     reverse(arr.begin(),arr.begin()+n);
// }

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int d;
    cin >> d;
    rightRotate(arr,n,d);
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    

    return 0;
}