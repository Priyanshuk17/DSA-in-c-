#include<bits/stdc++.h>
using namespace std;

int celebrityBrute(vector<vector<int>>& mat, int n) {
    vector<int> knowMe(n, 0), iKnow(n, 0);

    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            if(mat[i][j] == 1) {
                iKnow[i]++;
                knowMe[j]++;
            }
        }
    }
    for(int i = 0;i < n;i++) {
        if(knowMe[i] == n - 1 && iKnow[i] == 0) 
            return i;
    }
    return -1;
}
int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {0, 0, 0, 0},
        {0, 1, 1, 0}
    };

    int n = mat.size();
    cout << celebrityBrute(mat, n);
    return 0;
}