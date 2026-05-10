#include<bits/stdc++.h>
using namespace std;

int linearSearch(int n, int num, vector<int> &arr) {
    for(int i=0;i<n;i++) {
        if(arr[i] == num) {
            return i;
        }
    }
    return -1;
}
int main() {
    int n;
    cout << "Enter numbers of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    cout << "The number is at index " << linearSearch(n,4, arr);

    return 0;
}