#include<bits/stdc++.h>
using namespace std;

int largestEle(int arr[], int n) {
    int lar = arr[0];
    for(int i=0;i<n;i++) {
        if(arr[i] > lar){
            lar = arr[i];
        }
    }
    return lar;
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
    cout << largestEle(arr, n);

    return 0;
}