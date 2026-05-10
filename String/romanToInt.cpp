#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> mp = {
        {'I', 1}, {'V', 5}, {'X',10}, {'L', 50},{'C', 100}, {'D', 500}, {'M', 1000}
    };
    int result = 0;
    int prev = 0;
    for(int i = s.size() - 1; i>=0; i--) {
        int curr = mp[s[i]];
        if(curr < prev) {
            result -= curr;
        } else {
            result += curr;
        }
        prev = curr;
    }
    return result;
}

int main() {
    string s = "MCMXCIV";
    cout << romanToInt(s);

    return 0;
}