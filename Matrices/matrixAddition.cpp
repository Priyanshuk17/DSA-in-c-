#include<bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int A[100][100], B[100][100], C[100][100];

    // Input first matrix
    for (int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> B[i][j];
        }
    }
    // Matrix Addition
    for(int i = 0;i<r;i++) {
        for(int j=0;j<c;j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    for(int i = 0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cout << C[i][j] << " ";
        }
    }


    return 0;
}