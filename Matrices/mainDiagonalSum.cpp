#include <iostream>
#include <vector>
using namespace std;

int diagonalSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    // Input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << diagonalSum(matrix);
    return 0;
}