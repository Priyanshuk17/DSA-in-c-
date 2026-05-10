#include<bits/stdc++.h>
using namespace std;

void helper(vector<string> &v, int n, int oc, int cc, string s) {
    if(oc == n && cc == n) {
        v.push_back(s);
        return;
    }

    if(oc < n) {
        helper(v, n, oc + 1, cc, s + "(");
    }
    if(cc < oc) {
        helper(v, n, oc, cc + 1, s + ")");
    }
}

vector<string> generateParentheses(int n) {
    vector<string> v;
    int oc = 0, cc = 0;
    helper(v, n, oc, cc, "");
    return v;
}

int main () {
    int n;
    cout << "Enter no between 1 to 8:- " << endl;
    cin >> n;
    vector<string> result = generateParentheses(n);
    for(auto it : result) {
        cout << it << " ";
    }
    return 0;
}