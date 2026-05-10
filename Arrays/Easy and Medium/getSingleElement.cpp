#include<bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr) {
    int xorr = 0;
    for(int i=0;i<arr.size();i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int main() {
    int n;
    cout << "Enter numbers of elements in an array: "<<endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: " << endl;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
   
    cout << getSingleElement(arr) << endl;
    return 0;
}