#include<bits/stdc++.h>
using namespace std;

string reverseWords(string &s) {
    int n = s.size();
    vector<string> words;
    string word = "";
    for(int i=0;i<n;i++) {
        if(s[i] != ' ') {
            word += s[i];
        }
        else if(!word.empty()) {
            words.push_back(word);
            word = "";
        }     
    }
    if(!word.empty()) {
        words.push_back(word);
    }
    reverse(words.begin(), words.end());
    string res = "";
    for(int i=0;i<words.size();i++) {
        res += words[i];
        if(i < words.size() - 1) {
            res += " ";
        }
    }
    return res;
}

int main() {    
    string s;
    getline(cin, s);
    cout << reverseWords(s);

    return 0;
}