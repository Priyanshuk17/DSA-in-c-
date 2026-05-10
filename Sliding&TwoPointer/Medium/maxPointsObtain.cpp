#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int lSum = 0;
    int rSum = 0;
    int maxSum = 0;
    int n = cardPoints.size();
    for(int i = 0;i<k;i++) {
        lSum = lSum + cardPoints[i];
        maxSum = lSum;
    }
    int rInd = n-1;
    for(int i = k-1;i>=0;i--) {
        lSum = lSum - cardPoints[i];
        rSum = rSum + cardPoints[rInd];
        rInd--;
        maxSum = max(maxSum, lSum + rSum);
    }
    return maxSum;
}


int main() {
    vector<int> nums = {6, 2, 3, 4, 7, 2, 1, 7, 1};

    int res = maxScore(nums, 4);
    cout << res;

    return 0;
}