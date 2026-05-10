#include<bits/stdc++.h>
using namespace std;

// void rearrangeBySign(vector<int> &arr) {
//     int n = arr.size();
//     vector<int> pos, neg;
//     for(int i = 0;i<n;i++) {
//         if(arr[i] < 0) {
//             neg.push_back(arr[i]);
//         }
//         else {
//             pos.push_back(arr[i]);
//         }
//     }
    
//     if(pos.size() > neg.size()) {
//         for(int i = 0;i<neg.size();i++) {
//             arr[2*i] = pos[i];
//             arr[2*i+1] = neg[i];
//         }
//         int index = neg.size() * 2;
//         for(int i = neg.size(); i< pos.size();i++) {
//             arr[index] = pos[i];
//             index++;
//         }
//     }
//     else{
//         for(int i = 0;i<pos.size();i++) {
//             arr[2*i] = pos[i];
//             arr[2*i+1] = neg[i];
//         }
//         int index = pos.size() * 2;
//         for(int i = pos.size(); i< neg.size();i++) {
//             arr[index] = neg[i];
//             index++;
//         }
//     }
// }

// vector<int> next(vector<int> &arr) {
//     int ind = -1;
//     int n = arr.size();
//     for(int i = n-2;i>=0;i--) {
//         if(arr[i] < arr[i + 1]) {
//             ind = i;
//             break;
//         }
//     }
//     if(ind == -1) {
//         reverse(arr.begin(), arr.end());
//         return arr;
//     }
//     for(int i = n-1;i>=ind;i--) {
//         if(arr[i] > arr[ind]) {
//             swap(arr[i], arr[ind]);
//             break;
//         }
//     }
//     reverse(arr.begin() + ind + 1, arr.end());
//     return arr;
// }
// vector<int> leaders(vector<int> &arr) {
//     vector<int> ans;
//     bool leaders;
//     for(int i = 0;i<arr.size();i++) {
//         leaders = true;
//         for(int j = i;j<arr.size();j++) {
//             if(arr[j] > arr[i]) {
//                 leaders = false;
//                 break;
//             }
//         }
//         if(leaders == true) ans.push_back(arr[i]);
//     }
//     return ans;
// }
// vector<int> leaders(vector<int> &arr) {
//     int n = arr.size();
//     int maxi = INT_MIN;
//     vector<int> ans;
//     for(int i = n - 1;i >=0; i--) {
//         if(arr[i] > maxi) {
//             ans.push_back(arr[i]);
//         }
//         maxi = max(maxi, arr[i]);
//     }
//     return ans;
// }

// bool ls(vector<int> &arr, int x) {
//     int n = arr.size();
//     for(int i = 0;i<n;i++) {
//         if(arr[i] == x) {
//             return true;
//         }
//     }
//     return false;
// }

// int longest(vector<int> &arr) {
//     int n = arr.size();
//     int longest = 1;
//     int cnt;
//     for(int i=0;i<n;i++) {
//         int x = arr[i];
//         cnt = 1;
//         while(ls(arr, x+1)) {
//             x = x + 1;
//             cnt++;
//         }
//         longest = max(cnt, longest);
//     }
//     return longest;
// }

// int longest(vector<int> &arr) {
//     sort(arr.begin(), arr.end());
//     int n = arr.size();
//     int cnt = 0;
//     int lastSmaller = INT_MIN;
//     int longest = 1;
//     for(int i =0 ;i<n;i++) {
//         if(arr[i] - 1 == lastSmaller) {
//             cnt = cnt+1;
//             lastSmaller = arr[i];
//         }
//         else if(lastSmaller != arr[i]) {
//             cnt = 1;
//             lastSmaller = arr[i];
//         }
//         longest = max(cnt, longest);
//     }
//     return longest;
// }
// int longset(vector<int> &arr) {
//     int n = arr.size();
//     if(n == 0) return 0;
//     int longest = 1;
//     unordered_set<int> st;
//     for(int i=0;i<n;i++) {
//         st.insert(arr[i]);
//     }
//     for(auto it : st) {
//         if(st.find(it - 1) == st.end()) {
//             int cnt = 1;
//             int x = it;
        
//             while(st.find(x+1) != st.end()) {
//                 x = x + 1;
//                 cnt = cnt + 1;
//             }
//             longest = max(longest, cnt);
//         }
        
//     }
//     return longest;

// }

// vector<vector<int>> setMatrix(vector<vector<int>> &mat) {
//     int n = mat.size();
//     int m = mat[0].size();
//     int row[n] = {0};
//     int col[m] = {0};
//     for(int i=0;i<n;i++) {
//         for(int j = 0;j<m;j++) {
//             if(mat[i][j]==0) {
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }
//     for(int i=0;i<n;i++) {
//         for(int j=0;j<m;j++) {
//             if(row[i] || col[j]) {
//                 mat[i][j] = 0;
//             }
//         }
//     }
//     return mat;
// }
// vector<vector<int>> setMat(vector<vector<int>> &mat) {
//     int n = mat.size();
//     int m = mat[0].size();
//     // int row[n] = {0};  mat[i][..]
//     // int col[m] = {0};  mat[..][j]
//     int col0 = 1;
//     for(int i = 0;i<n;i++) {
//         for(int j = 0;j<m;j++) {
//             if(mat[i][j] == 0) {
//                 // mark the ith row
//                 mat[i][0] = 0;
//                 //mark the jth col
//                 if(j!=0)
//                     mat[0][j] = 0;
//                 else 
//                     col0 = 1;
//             }
//         }
//     }
//     for(int i=1;i<n;i++) {
//         for(int j =1;j<m;j++) {
//             if(mat[i][j] != 0) {
//                 if(mat[i][0]==0 || mat[0][j]==0) {
//                     mat[i][j] = 0;
//                 }
//             }
//         }
//     }
//     if(mat[0][0]==0) {
//         for(int j = 0;j<m;j++) mat[0][j] = 0;
//     }
//     if(col0 == 0) {
//         for(int i = 0;i<n;i++) {
//             mat[i][0] = 0;
//         }
//     }
//     return mat;
// }

// vector<vector<int>> setMat(vector<vector<int>> &mat) {
//     // int row[n] = {0}; // mat[..][0]
//     // int col[m] = {0}; // mat[0][..]
//     int n = mat.size();
//     int m = mat[0].size();
//     int col0 = 1;
//     for(int i = 0;i<n;i++) {
//         for(int j=0;j<m;j++) {
//             if(mat[i][j] == 0) {
//                 // mark the ith row
//                 mat[i][0] = 0;

//                 // mark the jth col
//                 if(j != 0) 
//                     mat[0][j] = 0;
//                 else 
//                     col0 = 0;
//             }
//         }
//     }
//     for(int i = 1;i<n;i++) {
//         for(int j = 1;j<m;j++) {
//             if(mat[i][j] != 0){
//                 if(mat[0][j]==0 || mat[i][0] == 0 ) {
//                     mat[i][j] = 0;
//                 }
//             }
//         }
//     }
//     if(mat[0][0] == 0 ) {
//         for(int j = 0;j<m;j++) mat[0][j] = 0;
//     }
//     if(col0 == 0) {
//         for(int i = 0;i<n;i++) {
//             mat[i][0] = 0;
//         }
//     }
//     return mat;

// }


// vector<vector<int>> rotate(vector<vector<int>> mat) {
//     int n = mat.size();
//     int m = mat[0].size();
//     vector<vector<int>> ans(m, vector<int>(n));
//     for(int i=0;i<n;i++) {
//         for(int j=0;j<m;j++) {
//             ans[j][(n-1)-i] = mat[i][j]; 
//         }
//     }
//     return ans;
// }

// vector<vector<int>> rotate(vector<vector<int>> &mat) {
//     int n = mat.size();
//     int m = mat[0].size();
//     for(int i=0;i<n-1;i++) {
//         for(int j=i+1;j<n;j++) {
//             swap(mat[i][j], mat[j][i]);
//         }
//     }
//     for(int i = 0;i<n;i++) {
//         reverse(mat[i].begin(), mat[i].end());
//     }
//     return mat;
// }

int findSubarray(vector<int> &arr, int k) {
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0;
    int cnt = 0;
    for(int i=0;i<arr.size();i++) {
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    
    return cnt;
}
int main() {
    // vector<vector<int>> mat = {
    //     {13, 5, 8, 16},
    //     {14, 9, 3, 6},
    //     {1, 4, 1, 20},
    //     {9, 28, 25, 16}
    // };
    // vector<vector<int>> ans = rotate(mat);
    vector<int> arr = {1, 2,3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;
    int ans = findSubarray(arr, k);
    cout << ans;
    // for(auto it : ans) {
    //     for(auto i : it) {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}