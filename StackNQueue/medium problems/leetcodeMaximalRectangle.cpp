class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        // heights[i][j] = height of histogram at row i, column j
        vector<vector<int>> heights(m, vector<int>(n, 0));

        // Build histogram heights column-wise
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] == '1')
                    sum++;
                else
                    sum = 0;

                heights[i][j] = sum;
            }
        }

        int maxArea = 0;

        // Apply Largest Rectangle in Histogram for each row
        for (int i = 0; i < m; i++) {
            maxArea = max(maxArea, largestRectangleArea(heights[i]));
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};
