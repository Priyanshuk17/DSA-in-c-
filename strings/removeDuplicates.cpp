#include<bits/stdc++.h>
using namespace std;

// TC -> O(n) SC -> O(n)
//  this question is to remove the duplicate characters from a string.
//  how to do it:-
// 1. take the string as input.
// 2. create an unordered_map to store the characters of the string.        
// 3. iterate through the string and for each character, check if it is present in the unordered_map. If it is not present, then we will add it to the result string and mark it as visited in the unordered_map.
// 4. finally, return the result string.
string removeDuplicates(string &s) {
    unordered_map<char, bool> visited;
    string res;
    for(char ch : s) {
        if(!visited[ch]) {
            res += ch;
            visited[ch] = true;
        }
    }
    return res;
}

int main() {
    string s;
    getline(cin, s);
    string res = removeDuplicates(s);
    cout << res;

    return 0;
}