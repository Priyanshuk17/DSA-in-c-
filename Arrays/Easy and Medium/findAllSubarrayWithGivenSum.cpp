#include<bits/stdc++.h>
using namespace std;

int findAllSubarrayWithGivenSum(vector<int> &arr, int k) {
    unordered_map<int, int> mpp;
    int preSum = 0, cnt = 0;
    mpp[0] = 1;
    // O(N x log N) -> if we use map ds
    // N is for running loop and log N for map traversal
    // if we use unordered map then for best and average case
    // will take O(1) but if collisions take place 
    // worst will take O(N) time complexity
    // SC -> O(N)
    for(int i = 0;i<arr.size();i++) {
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    return cnt;
}
int main() {


    return 0;
}