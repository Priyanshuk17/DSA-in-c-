#include<bits/stdc++.h>
using namespace std;

// string removeVowels(string &s) {
//     string res = "";
//     for(char ch : s) {
//         // convert to lowercase for comparison
//         char lower = tolower(ch);
//         if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
//             continue;
//         }
//         res += ch;
//     }
//     return res;
// }

string removespaces(string s) {
    string res = "";
    for(char c : s) {
        if(c != ' ' && c != '\t' && c != '\n') {
            res += c;
        }
    }
    return res;
}

string removeChar(string s) {
    string res = "";
    for(char c : s) {
        if(isalnum(c) || c == ' ')
            res += c;
    }
    return res;
}
int main() {
    string s = "Take#%^& You Forward";
    string res = removeChar(s);
    cout << res;
    return 0;
}