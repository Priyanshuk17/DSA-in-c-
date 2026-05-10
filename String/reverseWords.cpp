#include<bits/stdc++.h>
using namespace std;

// string reverseWords(string s) {
//     vector<string> words;
//     string word = "";
//     // step 1 & 2 extract words
//     for(char c : s) {
//         if(c != ' ') {
//             word += c;
//         } else {
//             if (!word.empty()) {
//                 words.push_back(word);
//                 word = "";
//             }   
//         }
//     }
//     // step 3 last word
//     if(!word.empty()) {
//         words.push_back(word);
//     }
//     // step 4 : build result in reverse order
//     string result = "";
//     for(int i = words.size() -1;i>=0;i--) {
//         result += words[i];
//         if(i != 0) result += " ";
//     }
//     return result;
// }


string reverseWords(string s) {
    int n = s.length();
    string ans = "";
    // reverse Position
    reverse(s.begin(), s.end());
    for(int i=0;i<n;i++) {
        string word = "";
        while(i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }
        // Reverse Individuals
        reverse(word.begin(), word.end());
        if(word.length() > 0) {
            ans += " " + word;
        }
    }
    return ans.substr(1);
}

int main() {
    string s;
    getline(cin, s);

    cout << reverseWords(s);

    return 0;
}