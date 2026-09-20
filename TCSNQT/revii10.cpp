#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> func(vector<pair<int, int>> &arr)
{
    vector<pair<int, int>> ans;
    int n = arr.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i].first == arr[j].second &&
               arr[i].second == arr[j].first)
            {
                ans.push_back(arr[i]);
            }
        }
    }
    return ans;
}


int main()
{
    vector<pair<int,int>> arr = {
        {1,2},
        {2,1},
        {3,4},
        {4,5},
        {5,4}
    };
    vector<pair<int,int>> ans = func(arr);
    for(auto it : ans)
    {
        cout << "(" << it.first << "," << it.second << ") ";
    }
    return 0;
}

// int maxProductSubarray(vector<int> &nums) {
//     int n = nums.size();
//     int maxProd = nums[0];
//     int minProd = nums[0];
//     int ans = nums[0];
//     for(int i=0;i<n;i++) {
//         if(nums[i] < 0) {
//             swap(maxProd, minProd);
//         }
//         maxProd = max(nums[i], maxProd * nums[i]);
//         minProd = min(nums[i], minProd * nums[i]);
//         ans = max(ans, maxProd);
//     }
//     return maxProd;
// }