#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter your array size.." << endl;
    cin >> n;
    int arr[n];
    cout << "enter your array..." << endl;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> mpp;// map place all the value in sorted order and in unordered map it store as it is
    for(int i=0;i<n;i++) {
        mpp[arr[i]]++;
    }
    for(auto it : mpp) {
        cout << it.first << "-->" << it.second << endl;
    }
    // pre-compute
    int q;
    cin >> q;
    while(q--) {
        int number;
        cout << "Enter number to fetch" << endl;
        cin >> number;
        // fetch
        cout << "Fetchng.." <<  mpp[number] << endl;
    }
    return 0;
}