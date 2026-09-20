#include<bits/stdc++.h>
using namespace std;


// this question is to change every letter in a string to its next letter.
// how to do it:-
// 1. take the string as input. 
// 2. iterate through the string and check each character.
// 3. if the character is 'z', then we will change it to 'a     
// 4. if the character is 'Z', then we will change it to 'A'.
// 5. for all other characters, we will change it to its next character by adding 1 to its ascii value.
string changeEveryLetter(string &s) {
    string res = "";
    for (char ch : s) {
        if (ch == 'z')
            res += 'a';
        else if (ch == 'Z')
            res += 'A';
        else
            res += ch + 1;
    }
    return res;
}

int main() {
    string s;
    getline(cin, s);
    cout << changeEveryLetter(s);
    return 0;
}