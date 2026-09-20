#include<bits/stdc++.h>
using namespace std;

void boundaryTraversal(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    // Top row
    for (int j = 0; j < cols; j++) {
        cout << matrix[0][j] << " ";
    }
    // Right column
    for (int i = 1; i < rows; i++) {
        cout << matrix[i][cols - 1] << " ";
    }
    // Bottom row
    for (int j = cols - 2; j >= 0; j--) {
        cout << matrix[rows - 1][j] << " ";
    }
    // Left column
    for (int i = rows - 2; i >= 1; i--) {
        cout << matrix[i][0] << " ";
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    // Input
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    boundaryTraversal(matrix);
    return 0;
}