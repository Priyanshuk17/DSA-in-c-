#include<bits/stdc++.h>
using namespace std;

int computeSum(vector<int>& nums, int d) {
    int sum = 0;
    for(int n : nums) {
        sum += ceil((double)(n) / d);
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    if(n > threshold) return -1;
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = high;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int sum = computeSum(nums, mid);
        if(sum <= threshold) {
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    vector<int> nums = {11, 11, 22, 33, 44};
    int threshold = 5;
    cout << "Smallest Divisor: " << smallestDivisor(nums, threshold);
    return 0;
}