#include<bits/stdc++.h>
using namespace std;

int func(vector<int> arr)  {
    int n = arr.size();
    vector<int> temp = arr;
    sort(temp.begin(),temp.end());
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(arr[i] != temp[i]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    vector<int> arr = {7, 5, 4, 3, 2, 8};
    int res = func(arr);
    cout << res;
        
}