#include<bits/stdc++.h>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += mat[i][i];
        sum += mat[i][n-1-i];
    }
    if(n%2==1) {
        sum -= mat[n/2][n/2];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> mat[i][j];
        }
    }
    int res = diagonalSum(mat);
    cout << res;
    return 0;
}