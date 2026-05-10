#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
    // transpose
    // O(n / 2 * N / 2)
    for(int i = 0;i<n-1;i++) {
        for(int j = i+1;j<n;j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    // reverse
    // O(N * N / 2)
    for(int i = 0;i<n;i++) {
        // row is mat[i]
        reverse(mat[i].begin(), mat[i].end());
    }
}
int main() {

    return 0;
}