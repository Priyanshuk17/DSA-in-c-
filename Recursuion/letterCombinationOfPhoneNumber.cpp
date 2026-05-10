#include<bits/stdc++.h>
using namespace std;

void solve(int index, string &digits, string &current, vector<string> &mapping, vector<string> &ans) {
    if(index == digits.size()) {
        ans.push_back(current);
        return;
    }

    string letters = mapping[digits[index] - '0'];

    for(char ch : letters) {
        current.push_back(ch);
        solve(index + 1, digits, current, mapping, ans);
        current.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if(digits.empty()) return {};

    vector<string> mapping = {
        "", "", "abc", "def", "ghi", 
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> ans;   // ✅ local
    string current = "";

    solve(0, digits, current, mapping, ans);

    return ans;
}


int main() {
    string digits = "5623";
    vector<string> result = letterCombinations(digits);
    for(auto it : result) {
        cout << it << " ";
    }
    return 0;
}