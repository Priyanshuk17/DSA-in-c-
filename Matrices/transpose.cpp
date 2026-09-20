#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int matrix[100][100];
    // Input matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }
    // Transpose
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}