#include<bits/stdc++.h>
using namespace std;

// this question is to find the maximum repeating character in a string.
// how to do it:-
// 1. take the string as input.
// 2. create an unordered_map to store the frequency of each character in the string.
// 3. iterate through the string and for each character, increment its corresponding value in the unordered_map.
// 4. finally, iterate through the unordered_map to find the character with the maximum frequency
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