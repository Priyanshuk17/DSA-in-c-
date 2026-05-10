#include<bits/stdc++.h>
using namespace std;

// q
// int maxDepth(string s) {
//     stack<int> st;
//     int n = 0;
//     int cnt = 0;
//     for(char c : s) {
//         if(c == '(') {
//             st.push(c);
//             n++;
//             cnt = max(cnt, n);
//         }
//         if(c == ')') {
//             st.pop();
//             n--;
//             cnt = max(cnt, n);
//         }
//     }
//     return cnt;
// }

// brute
// int maxDepth(string s) {
//     int maxDepth = 0;
//     int n = s.size();

//     for(int i = 0;i<n;i++) {
//         if(s[i] == '(') {
//             int depth = 0;
//             for(int j = i; j<n; j++) {
//                 if(s[j] == '(') {
//                     depth++;
//                     maxDepth = max(maxDepth, depth);
//                 }
//                 else if(s[j] == ')') {
//                     depth--;
//                 }
//                 if(depth == 0) break;
//             }
//         }
//     }
//     return maxDepth;
// }

int maxDepth(string s) {
    int n = 0;
    int cnt = 0;
    for(char c : s) {
        if(c == '(') {
            n++;
            cnt = max(cnt, n);
        }
        if(c == ')') {
            n--;
            cnt = max(cnt, n);
        }
    }
    return cnt;
}

int main() {

    return 0;
}