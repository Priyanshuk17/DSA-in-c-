#include<bits/stdc++.h>
using namespace std;

int findConsecutiveOnes(vector<int> &arr) {
    int maxi = 0;
    int cnt = 0;
    for(int i=0;i<arr.size();i++) {
        if(arr[i] == 1) {
            cnt++;
            maxi = max(maxi, cnt);
        }
        else {
            cnt = 0;
        }
    }
    return maxi;
}

int main() {
    int n;
    cout << "Enter numbers of elements of first array: "<<endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: " << endl;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
   
    cout << findConsecutiveOnes(arr) << endl;
    return 0;
}