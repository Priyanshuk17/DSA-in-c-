#include<bits/stdc++.h>
using namespace std;

void rotateArray(int n, int arr[]) {
   int temp = arr[0];
   for(int i=1;i<n;i++) {
    arr[i-1] = arr[i];
   }
   arr[n-1] = temp;
}
// This will give size of array the array 
// In which we have storing only the elments
// Which appearing one time
int main() {
    int n;
    cout << "Enter the size of array \n";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements \n";
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    rotateArray(n, arr);
    cout << "Rotate Array is :- " << endl;
    for(int i=0;i<n;i++) {
        cout  << arr[i] << " " ; 
    }

    return 0;
}