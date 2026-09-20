#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeElementBySign(vector<int> &arr) {
    int n = arr.size();
    int posInd = 0;
    int negInd = 1;
    vector<int> ans(n, 0);
    for(int i=0;i<n;i++) {
        if(arr[i] >= 0) {
            ans[posInd] = arr[i];
            posInd+=2;
        }
        else {
            ans[negInd] = arr[i];
            negInd+=2;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {-1, 0, 5, -3, 2, 5};
    vector<int> ans = rearrangeElementBySign(arr);
    for(int i=0;i<arr.size();i++) {
        cout << ans[i] << " "; 
    }
    return 0;
}