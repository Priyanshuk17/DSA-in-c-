#include<bits/stdc++.h>
using namespace std;

int func(int target, vector<int> &nums) {
    int n = nums.size();
    int i = 0;
    int j = 0;
    int minL = INT_MAX;
    int sum = 0;
    while(j < n) {
        sum += nums[j];
        while(sum >= target) {
            minL = min(minL, j-i+1);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    return minL;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int res = func(target, nums);
    cout << res;
    return 0;
}