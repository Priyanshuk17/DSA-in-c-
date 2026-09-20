#include<bits/stdc++.h>
using namespace std;

void maximumRepeating(string &s) {
    unordered_map<char, int> mpp;
    for(auto it : s) {
        mpp[it]++;
    }
    char ans;
    int maxFreq = 0;
    for(auto it : mpp) {
        if(it.second > maxFreq) {
            ans = it.first;
            maxFreq = it.second;
        }
    }
    cout << "Maximum occuring character is " << ans << " ";
    cout << "With Frequency " << maxFreq;
}
int main() {
    string s;
    getline(cin , s);
    maximumRepeating(s);

    return 0;
}