#include<bits/stdc++.h>
using namespace std;

long long maximumProfit(vector<int>& arr) {
    int mini = arr[0];
    int maxProfit = 0;
    int n = arr.size();
    for(int i = 0;i<n;i++) {
        int cost = arr[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini,arr[i]);
    }
    return maxProfit;
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
   
   
    cout << maximumProfit(arr);
    
    return 0;
}