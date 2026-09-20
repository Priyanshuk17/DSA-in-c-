#include<bits/stdc++.h>
using namespace std;

// this question is to count the number of words in a string.
// how to do it:-
// 1. take the string as input.
// 2. iterate through the string and check each character.
// 3. if the character is not a space and either it is the first character or the previous character is a space, then we will increment the count of words.
int countWords(string &s) {
    int cnt = 0;
    for(int i=0;i<s.size();i++) {
        if(s[i] != ' ' && ( i == 0 || s[i - 1] == ' ' )) {
            cnt++;
        }
    }
    return cnt + 1;
}
int main() {
    string s;
    getline(cin, s);
    cout << countWords(s);
    return 0;
}