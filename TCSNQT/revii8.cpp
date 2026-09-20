#include<bits/stdc++.h>
using namespace std;


int func(vector<int> &arr) {
    int n = arr.size();
    int maxProd = INT_MIN; 
    for(int i=0;i<n;i++) {
        int prod = arr[i];
        for(int j=i+1;j<n;j++) {
            prod *= arr[j];
            maxProd = max(prod, maxProd);
        }
    }
    return maxProd;
}

int main() {
    vector<int> arr = {2, 3, 4};
    int res = func(arr);
    cout << res;
    return 0;
}