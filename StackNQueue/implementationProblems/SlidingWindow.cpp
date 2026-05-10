#include<bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximum(vector<int>& nums, int k) {
    deque<int> dq; // stores indices
    vector<int> result;

    for(int i = 0;i < nums.size(); i++) {
        // Remove elements out of current window
        if(!dq.empty() && dq.front() == i-k) {
            dq.pop_front();
        }
        // Remove smaller elements
        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        // Push current index
        dq.push_back(i);

        // Store result when window size >= k
        if(i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 7, 6};
    int k = 3;

    vector<int> ans = slidingWindowMaximum(nums, k);

    cout << "Sliding window maximums: ";
    for(int x : ans) {
        cout << x << " ";
    }
    return 0;
}