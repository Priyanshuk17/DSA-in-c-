#include<bits/stdc++.h>
using namespace std;

void func(vector<int> &arr) {
    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while(mid <= high) {
        if(arr[mid]==0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        if(arr[mid]==1){
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> arr = {0, 2, 2, 1, 0, 1, 2};
    func(arr);
    int n = arr.size();
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

