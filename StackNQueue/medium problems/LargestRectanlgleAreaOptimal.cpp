#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();
    stack<int> st; // stores indices

    int maxArea = 0;
    // Traverse histrogram
    for(int i = 0;i < n;i++) {
        // while current bar is smaller than stack top
        while(!st.empty() && arr[st.top()] > arr[i]) {
            int element = st.top();
            st.pop();
            int nse = i; // next smaller element
            int pse = st.empty() ? -1 : st.top(); // Previous smaller element
            int width = nse - pse - 1;
            int area = arr[element] * width;
            maxArea = maxArea = max(maxArea, area);
        }
        st.push(i);
    }
    // Processing remaining elements in stack
    while(!st.empty()) {
        int element = st.top();
        st.pop();
        int nse = n; // no smaller on right
        int pse = st.empty() ? -1 : st.top(); // previous smaller
        int width = nse - pse -1;
        int area = arr[element] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    vector<int> arr = {6,6,6,6,6,6};
    cout << "Largest Rectangle Area = " << largestRectangleArea(arr) << endl;
    return 0;
}