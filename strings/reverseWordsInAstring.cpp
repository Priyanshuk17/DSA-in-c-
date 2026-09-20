#include<bits/stdc++.h>
using namespace std;

// this question is to reverse the words in a string.
// how to do it:-
// 1. take the string as input.
// 2. iterate through the string and check each character.      
// 3. if the character is not a space, then we will add it to the current word. 
// 4. if the character is a space, then we will add the current word to a vector of words and reset the current word.
// 5. finally, we will reverse the vector of words and join them to form the final string.
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