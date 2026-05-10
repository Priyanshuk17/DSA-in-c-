#include<bits/stdc++.h>
using namespace std;

vector<int> singleNum(vector<int> &nums) {
    long long xorr = 0;
    for(int i=0;i<nums.size();i++) {
        xorr = xorr ^ nums[i];
    }
    long rightMost = xorr & ~(xorr-1);
    int b1 = 0;
    int b2 = 0;
    for(int i=0;i<nums.size();i++) {
        if(nums[i] &rightMost) {
            b1 ^= nums[i];
        }else {
            b2 ^= nums[i];
        }
    }
    
    return {b1, b2};
}

int main() {
    vector<int> nums = {2, 4, 2, 6, 3, 7, 7, 3};
    vector<int> ans = singleNum(nums);
    for(auto it : ans) {
        cout << it << " ";
    }

    return 0;
}