#include<bits/stdc++.h>
using namespace std;

//brute
string removeOutermostParentheses(string s) {
    string result = "";
    int count = 0;
    int start = 0;

    for(int i = 0;i<s.size();i++) {
        if(s[i] == '(') count++;
        else count--;

        if(count==0) {
            result += s.substr(start + 1, i - start - 1); // substr(start, length)
            start = i + 1;
        }
    }
    return result;
}

// Optimal(slight better)
// string removeOutermostParentheses(string s) {
//     string result = "";
//     int count = 0;
//     for(char c : s) {
//         if(c == '(') {
//             if(count > 0) result += c;
//             count++;
//         }else {
//             count--;
//             if(count > 0) result += c;
//         }
//     }
//     return result;
// }
int main() {
    string s;
    cin >> s;

    cout << removeOutermostParentheses(s);

    return 0;
}