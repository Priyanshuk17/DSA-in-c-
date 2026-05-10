#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& arr) {
    int n = arr.size();
    int posIndex = 0;
    int negIndex = 1;
    vector<int> ans(n, 0);
    for(int i = 0;i<n;i++) {
        if(arr[i] < 0) {
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
        else {
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
    }
    return ans;
}

int main() {
    int n; // even number
    cout << "Enter numbers of elements of first array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<int> arranged = rearrangeArray(arr);

    cout << "Arranged array:\n";
    for(int num: arranged) {
        cout << num << " "; 
    }
    cout << endl;
    return 0;
}