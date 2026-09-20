#include<bits/stdc++.h>
using namespace std;

int noOfSubarrays(vector<int> &nums, int k, int threshold) {
    int n = nums.size();
    int sum = 0;
    int count = 0;
    for(int i=0;i<k;i++) {
        sum += nums[i];
    }
    int target = k * threshold;
    if(sum >= target) {
        count++;
    }
    for(int i=k;i<n;i++) {
        sum += nums[i];
        sum -= nums[i-k];
        if(sum >= target) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> arr = {2, 2, 2, 2, 5, 5, 5, 8};
    int k = 3;
    int threshold = 4;
    int res = noOfSubarrays(arr, k, threshold);
    cout << res;
    return 0;
}