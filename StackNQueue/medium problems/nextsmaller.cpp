#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;

    // Step 1: Process nums
    for (int i = 0; i<n; i++) {
        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(nums[i]);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    vector<int> nums(n);

    for(int i=0;i<n;i++) {
        cin >> nums[i];
    }
    
    vector<int> ans = nextSmallerElement(nums);
    
    for(int i=0;i<n;i++) {
        cout << ans[i] << " ";
    }
    return 0;
}