#include<bits/stdc++.h>
using namespace std;

// ----------------- Largest rectangle in Histrogram
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    for(int i = 0;i<=n;i++) {

        int currHeight = (i == n ? 0 : heights[i]);
        while(!st.empty() && currHeight < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();

            int width;
            if(st.empty()) {
                width = i;
            } else {
                width = i - st.top() - 1;
            }
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }
    return maxArea;
}

// ----------------- Maximum Rectangle of 1s--------//
int maxRectangle(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> PSum(m, vector<int>(n, 0));

    int maxArea = 0;

    // Build prefix sum matrix column wise
    for(int j = 0;j < n;j++) {
        int sum = 0;
        for(int i = 0;i<m;i++) {
            if(mat[i][j] == 1)
                sum += 1;
            else
                sum = 0;

            PSum[i][j] = sum;
        }
    }

    // Apply largest rectangle in histrogram for each row

    for(int i = 0;i < m;i++) {
        maxArea = max(maxArea, largestRectangleArea(PSum[i]));
    }
    return maxArea;
}

int main() {
    vector<vector<int>> mat = {
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    cout << "Maximum Rectangle Area With All 1s = " << maxRectangle(mat) << endl;

    return 0;
}