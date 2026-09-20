#include<bits/stdc++.h>
using namespace std;

long long func(vector<int> &nums, int k){
    int n = nums.size();
    int result = 0;
    int currWindowSum = 0;
    unordered_set<int> st;
    int i = 0;
    int j = 0;
    while(j<n) {
        while(st.count(nums[j])) {
            currWindowSum -= nums[i];
            st.erase(nums[i]);
            i++;
        }
        currWindowSum += nums[j];
        st.insert(nums[j]);
        if(j-i+1 == k) {
            result = max(result, currWindowSum);
            currWindowSum -= nums[i];
            st.erase(nums[i]);
            i++;
        }
        j++;
    }
    return result;
}

int main() {
    vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
    int k = 3;
    long long ans = func(nums, k);
    cout << ans;
    return 0;
}