#include<bits/stdc++.h>
using namespace std;


int celebrityOptimized(vector<vector<int>> & mat, int n) {
    int top = 0, down = n - 1;

    while(top < down) {
        if(mat[top][down] == 1){
            top++;
        }
        else if(mat[down][top] == 1){
            down--;
        }
        else{
            top++;
            down--;
        }
    }
    int candidate = down;
    // verification
    for(int i = 0; i < n;i++) {
        if(i != candidate) {
            if(mat[candidate][i] == 1 || mat[i][candidate] == 0)
                return -1;
        }
    }
    return candidate;
}
int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {0, 0, 0, 0},
        {0, 1, 1, 0}
    };

    int n = mat.size();
    cout << celebrityOptimized(mat, n);
    return 0;
}