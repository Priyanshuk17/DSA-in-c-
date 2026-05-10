#include<bits/stdc++.h>
using namespace std;

// vector<int> generateRow(int row) {
//     vector<int> temp;
//     long long ans = 1;
//     temp.push_back(1);
//     for(int col = 1;col<row;col++) {
//         ans = ans * (row - col);
//         ans = ans / col;
//         temp.push_back(ans);
//     }
//     return temp;
// }

// vector<vector<int>> generate(int numRow) {
//     vector<vector<int>> ans;
//     for(int i=1;i<=numRow;i++) {
//         ans.push_back(generateRow(i));
//     }
//     return ans;
// }


// vector<int> generateRow(int row) {
//     long long ans = 1;
//     vector<int> temp;
//     temp.push_back(1);
//     for(int col = 1;col<row;col++) {
//         ans = ans * (row - col);
//         ans = ans / col;
//         temp.push_back(ans);
//     }
//     return temp;
// }

// vector<vector<int>> generate(int numRows) {
//     vector<vector<int>> ans;
//     for(int i=1;i<=numRows;i++) {
//         ans.push_back(generateRow(i));
//     }
//     return ans;
// }

// vector<int> majority(vector<int> &arr) {
//     vector<int> ans;
//     int n = arr.size();
//     for(int i=0;i<n;i++) {
//         if(ans.size() == 0 || ans[0]!=arr[i]) {
//             int cnt = 0;
//             for(int j=0;j<n;j++) {
//                 if(arr[j]==arr[i]) {
//                     cnt = cnt + 1;
//                 }
//             }
//             if(cnt > n/3) {
//                 ans.push_back(arr[i]);
//             }
//         }
//         if(ans.size() > 2) break;
//     }
//     return ans;
// }

// vector<int> majority(vector<int> &arr) {
//     int n = arr.size();
//     unordered_map<int, int> mpp;
//     vector<int> ans;
//     int threshold = (n/3) + 1;
//     for(int i=0;i<n;i++) {
//         mpp[arr[i]]++;
//         if(mpp[arr[i]]==threshold) {
//             ans.push_back(arr[i]);
//         }
//         if(ans.size() == 2) break;
//     }
//     return ans;
// }
// vector<int> majority(vector<int> &arr) {
//     int n = arr.size();
//     int cnt1 = 0, cnt2 = 0;
//     int el1 = 0, el2 = 0;

//     // Step 1: Find candidates
//     for(int i = 0; i < n; i++) {
//         if(cnt1 == 0 && arr[i] != el2) {
//             el1 = arr[i];
//             cnt1 = 1;
//         }
//         else if(cnt2 == 0 && arr[i] != el1) {
//             el2 = arr[i];
//             cnt2 = 1;
//         }
//         else if(arr[i] == el1) cnt1++;
//         else if(arr[i] == el2) cnt2++;
//         else {
//             cnt1--;
//             cnt2--;
//         }
//     }

//     // Step 2: Verify counts
//     cnt1 = cnt2 = 0;
//     for(int i = 0; i < n; i++) {
//         if(arr[i] == el1) cnt1++;
//         else if(arr[i] == el2) cnt2++;
//     }

//     // Step 3: Add valid answers
//     vector<int> ans;
//     if(cnt1 > n/3) ans.push_back(el1);
//     if(cnt2 > n/3) ans.push_back(el2);

//     return ans;
// }

// vector<vector<int>> threeSu(vector<int> &arr) {
//     int n = arr.size();
//     set<vector<int>> st;
//     for(int i=0;i<n;i++) {
//         int sum = 0;
//         for(int j=i+1;j<n;j++) {
//             for(int k=j+1;k<n;k++) {
//                 if(arr[i]+arr[j]+arr[k]==0) {
//                     vector<int> temp = {arr[i], arr[j], arr[k]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
                
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end()); 
//     return ans;
// }
// vector<vector<int>> triplet(vector<int> &arr) {
//     int n = arr.size();
//     set<vector<int>> st;
//     for(int i=0;i<n;i++) {
//         set<int> hashset;
//         for(int j=i+1;j<n;j++) {
//             int third = -(arr[i] + arr[j]);
//             if(hashset.find(third) != hashset.end()) {
//                 vector<int> temp = {arr[i],arr[j],third};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//             }
//             hashset.insert(arr[j]);
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }
// vector<vector<int>> triplet(vector<int> &arr) {
//     vector<vector<int>> ans;
//     int n = arr.size();
//     sort(arr.begin(), arr.end());
//     for(int i=0;i<n;i++) {
//         if(i > 0 && arr[i] == arr[i-1]) continue;
//         int j = i + 1;
//         int k = n -1;
//         while(j<k) {
//             int sum = arr[i] + arr[j] + arr[k];
//             if(sum<0) {
//                 j++;
//             }
//             else if(sum > 0) {
//                 k--;
//             }
//             else{
//                 vector<int> temp = {arr[i], arr[j], arr[k]};
//                 ans.push_back(temp);
//                 j++;
//                 k--;
//                 if(j<k && arr[j] == arr[j-1]) j++;
//                 if(j<k && arr[k] == arr[k+1]) k--;
//             }
//         }
//     }
//     return ans;
// }

// vector<vector<int>> fourSum(vector<int> &arr, int target) {
//     int n = arr.size();
//     set<vector<int>> st;
//     for(int i=0;i<n;i++) {
//         for(int j=i+1;j<n;j++) {
//             for(int k=j+1;k<n;k++) {
//                 for(int l=k+1;l<n;l++) {
//                     long long sum = arr[i] + arr[j];
//                     sum += arr[k];
//                     sum += arr[l];
//                     if(sum == target) {
//                         vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }
// vector<vector<int>> fourSum(vector<int> &arr, int target) {
//     int n = arr.size();
//     set<vector<int>> st;

//     for(int i = 0; i < n; i++) {
//         for(int j = i + 1; j < n; j++) {
//             set<long long> hashset;
//             for(int k = j + 1; k < n; k++) {
//                 long long sum = (long long)arr[i] + arr[j] + arr[k];
//                 long long fourth = (long long)target - sum;
//                 if(hashset.find(fourth) != hashset.end()) {
//                     vector<int> temp = {arr[i], arr[j], arr[k], (int)fourth};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(arr[k]);
//             }
//         }
//     }
//     return vector<vector<int>>(st.begin(), st.end());
// }

int xorForK(vector<int> &arr, int k) {
    int n = arr.size();
    int cnt = 0;
    for(int i=0;i<n;i++) {
        int xorr = 0;
        for(int j=i;j<n;j++) {
            xorr = xorr ^ arr[j];
            if(xorr == k) cnt++;
        }
        
    }
    return cnt;
}

int main() {
    // int num = 10;
    vector<int> arr = {4, 2, 2, 6, 4};
    int  ans = xorForK(arr, 6);
    cout << ans;
    // for(auto it : ans) {
    //     cout << it << " ";
    // }

    // vector<int> arr = {1, 0, -1, 0, -2, 2};
    // vector<vector<int>> ans = fourSum(arr, 0);
    // for(auto it : ans) {
    //     for(auto i : it ) {
    //         cout << i << " "; 
    //     }
    //     cout << endl;
    // }
    return 0;
}
