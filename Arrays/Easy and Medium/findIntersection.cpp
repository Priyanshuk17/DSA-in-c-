#include<bits/stdc++.h>
using namespace std;
// brute force method
// vector<int> findArrayIntersection(vector<int> &a, int n, vector<int> &b, int m) {
//     vector<int> ans;
//     int vis[m] = {0};
//     for(int i = 0;i<n;i++) {
//         for(int j = 0;j<m;j++) {
//             if(a[i] == b[j] && vis[j] == 0) {
//                 ans.push_back(a[i]);
//                 vis[j] = 1;
//                 break;
//             }
//             if(b[j] > a[i]) break;
//         }
//     }
//     return ans;
// }

// Optimal approach
vector<int> findArrayIntersection(vector<int> &a, int n, vector<int> &b, int m) {
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i<n && j<m) {
        if(a[i]<b[j]) {
            i++;
        }
        else if(b[j]<a[i]) {
            j++;
        }
        else {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}
int main() {

    // We have to give sorted array
    int n;
    cout << "Enter numbers of elements of first array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " elements:\n";
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    int m;
    cout << "Enter numbers of elements of second array: ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter " << m << " elements:\n";
    for(int i=0;i<n;i++) {
        cin >> b[i];
    }
    vector<int> Sorted = findArrayIntersection(a, n, b, m);

    cout << "Sorted intersection array:\n";
    for(int num: Sorted) {
        cout << num << " "; 
    }
    cout << endl;
    return 0;
}