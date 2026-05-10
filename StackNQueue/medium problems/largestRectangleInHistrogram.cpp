#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach to find largest rectangle area in Histogram
int largestarea(int arr[], int n) {
    int maxArea = 0;  // Variable to store maximum area found

    // Outer loop to set the starting index of the subarray
    for (int i = 0; i < n; i++) {
        int minHeight = INT_MAX;  // To track minimum height in the subarray

        // Inner loop to set the ending index of the subarray
        for (int j = i; j < n; j++) {
            // Update minimum height in the current window
            minHeight = min(minHeight, arr[j]);

            // Calculate area = height * width
            int width = j - i + 1;
            int area = minHeight * width;

            // Update maxArea if this area is larger
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;  // Return the largest area found
}


// class Solution {
//   public:
//     int largestRectangleArea(vector<int> &histo) {
//         stack<int> st; // Stack to store indices of the histogram bars
//         int maxA = 0;  // Variable to keep track of the maximum area
//         int n = histo.size();

//         // Loop through each bar including an imaginary bar at the end
//         for (int i = 0; i <= n; i++) {
//             // While current bar is smaller than the top of the stack or we reached the end
//             while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
//                 int height = histo[st.top()]; // Get the height of the bar at top of the stack
//                 st.pop(); // Remove that bar

//                 int width;
//                 if (st.empty()) {
//                     width = i; // All bars before were higher
//                 } else {
//                     width = i - st.top() - 1; // Width between current index and index at top of stack
//                 }

//                 // Calculate area and update maximum area
//                 maxA = max(maxA, width * height);
//             }
//             // Push current index into stack
//             st.push(i);
//         }
//         return maxA;
//     }
// };

vector<int> getPse(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;  // stores indices

    for(int i = 0;i<n;i++) {

        // pop until smaller element
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        // if stack is empty, no smaller on left
        pse[i] = st.empty() ? -1 : st.top();

        // push current index
        st.push(i);
    }
    return pse;
}

vector<int> getNse(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st; // stores indices

    for(int i = n-1;i>=0;i--) {

        // pop until smaller element is found
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        // if stack empty, no smaller on right
        nse[i] = st.empty() ? n : st.top();
        // push current index
        st.push(i);
    }
    return nse;
}

int largestRectangleArea(vector<int>& heights) {
    vector<int> pse = getPse(heights);
    vector<int> nse = getNse(heights);

    int maxArea = 0;
    int n = heights.size();

    for(int i = 0;i < n; i++) {
        int width = nse[i] - pse[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}
int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int result = largestRectangleArea(heights);
    cout << "Largest Rectangle Area = " << result << endl;

    return 0;
}

vector<int> getPse(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> pse(n);
    for(int i = 0;i<n;i++) {
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}