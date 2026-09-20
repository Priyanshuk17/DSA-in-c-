#include<bits/stdc++.h>
using namespace std;

string findLargestWord(string &s) {
    string word = "";
    string largest = "";
    for(char ch : s) {
        if(ch != ' ') {
            word += ch;
        } else {
            if(word.length() > largest.length()) {
                largest = word;
            }
            word = "";
        }
    }
    // check the last word
    if(word.length() > largest.length()) {
        largest = word;
    }
    return largest;
}
int main() {
    string s;
    getline(cin, s);
    cout << "Largest word: " << findLargestWord(s);
    return 0;
}