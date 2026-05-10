#include<bits/stdc++.h>
using namespace std;

void help(int i, int k, int sumTillNow, int n, vector<int> &subset, vector<vector<int>> &ans) {
    // if(sumTillNow > n ) return;
    // if(k == 0 ) {
    //     if(sumTillNow == n) {
    //         ans.push_back(subset);
    //     } 
    //     return;
    // }
    if( k < 0) return;
    if(sumTillNow == n) {
        if (k == 0) {
            ans.push_back(subset);
        }
        return;
    }
    if(i == 10) return;
    // pick 
    sumTillNow+=i;
    subset.push_back(i);
    help(i+1,k-1,sumTillNow, n, subset, ans);
    sumTillNow-=i;
    subset.pop_back();

    // ignore 
    help(i+1,k, sumTillNow, n, subset, ans);
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> subset;
    vector<vector<int>> ans;
    help(1, k, 0, n, subset, ans);
    return ans;
}

int main() {
    int k = 3;
    int n = 9;
    vector<vector<int>> result = combinationSum3(k, n);
    for (auto &vec : result) {
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}