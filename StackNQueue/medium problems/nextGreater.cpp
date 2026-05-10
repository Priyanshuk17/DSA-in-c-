#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp;
    stack<int> st;

    // Step 1: Process nums2
    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }
        mp[nums2[i]] = st.empty() ? -1 : st.top();
        st.push(nums2[i]);
    }
    // Step 2: Answer queries for nums1
    vector<int> ans;
    for (int x : nums1) {
        ans.push_back(mp[x]);
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the size of the first array" << endl;
    cin >> n;

    int m;
    cout << "Enter the size of the second array" << endl;
    cin >> m;

    vector<int> nums1(n);
    vector<int> nums2(m);

    for(int i=0;i<n;i++) {
        cin >> nums1[i];
    }
    for(int i=0;i<m;i++) {
        cin >> nums2[i];
    }
    vector<int> ans = nextGreaterElement(nums1, nums2);
    
    for(int i=0;i<n;i++) {
        cout << " " << ans[i];
    }
    return 0;
}