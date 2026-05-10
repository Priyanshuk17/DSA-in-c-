#include<bits/stdc++.h>
using namespace std;

vector<int> alternateNumbers(vector<int>&a) {
    vector<int> pos,neg;
    int n = a.size();
    for(int i=0;i<n;i++) {
        if(a[i] > 0){
            pos.push_back(a[i]);
        }
        else {
            neg.push_back(a[i]);
        }
    }
    if(pos.size() > neg.size()) {
        for(int i = 0;i<neg.size();i++) {
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        int index = neg.size() * 2;
        for(int i = neg.size();i<pos.size();i++) {
            a[index] = pos[i];
            index++;
        }
    }
    else {
        for(int i = 0;i<pos.size();i++) {
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        int index = pos.size() * 2;
        for(int i = pos.size();i<neg.size();i++) {
            a[index] = neg[i];
            index++;
        }

    }
    return a;
} 
vector<int> alternateNumbers(vector<int>&A) {
    int ind = -1;
    int n = A.size();
    for(int i=n-2;i>=0;i--) {
        if(A[i] < A[i+1]) {
            ind = i;
            break;
        }
    }
    if(ind == -1) {
        reverse(A.begin(),A.end());
        return A;
    }
    for(int i=n-1;i>ind;i--) {
        if(A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }
    reverse(A.begin() + ind + 1, A.end());

} 
int main() {

    return 0;
}