// #include<bits/stdc++.h>
// using namespace std;

// vector<int> Union(vector<int> a, vector<int> b) {

//     // We have to give sorted array
//     int n1 = a.size();
//     int n2 = b.size();
//     set<int> st;
//     for(int i=0;i<n1;i++) {
//         st.insert(a[i]);
//     }
//     for(int i=0;i<n2;i++) {
//         st.insert(b[i]);
//     }
//     vector<int> temp;
//     for(auto it : st) {
//         temp.push_back(it);
//     }
//     return temp;
// }
// int main() {
//     int n;
//     cout << "Enter numbers of elements of first array: ";
//     cin >> n;

//     vector<int> a(n);
//     cout << "Enter " << n << " elements:\n";
//     for(int i=0;i<n;i++) {
//         cin >> a[i];
//     }
//     int m;
//     cout << "Enter numbers of elements of second array: ";
//     cin >> m;
//     vector<int> b(m);
//     cout << "Enter " << m << " elements:\n";
//     for(int i=0;i<n;i++) {
//         cin >> b[i];
//     }
//     vector<int> sorted = Union(a, b);

//     cout << "Sorted union array:\n";
//     for(int num: sorted) {
//         cout << num << " "; 
//     }
//     cout << endl;
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
// Optimal Approach
vector<int> Union(vector<int> a, vector<int> b) {
    int n1 = a.size();
    int n2 = b.size();

    int i = 0;
    int j = 0;
    vector<int> unionArr;
    while(i<n1 && j<n2) {
        if(a[i] <= b[j]) {
            if(unionArr.size() == 0 || unionArr.back()!=a[i]) {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else {
            if(unionArr.size() == 0 || unionArr.back()!=b[j]) {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n1) {
        if(unionArr.size() == 0 || unionArr.back()!=a[i]) {
            unionArr.push_back(a[i]);
        }
        i++;
    }
    while(j<n2) {
        if(unionArr.size() == 0 || unionArr.back()!=b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }
    return unionArr;
}
int main() {
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
    vector<int> sorted = Union(a, b);

    cout << "Sorted union array:\n";
    for(int num: sorted) {
        cout << num << " "; 
    }
    cout << endl;
    return 0;
}