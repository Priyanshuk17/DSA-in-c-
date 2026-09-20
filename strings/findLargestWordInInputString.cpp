#include<bits/stdc++.h>
using namespace std;

// this question is to find the largest word in a string.
// how to do it:-
// 1. take the string as input.
// 2. iterate through the string and check each character.
// 3. if the character is not a space, then we will add it to the current word.
// 4. if the character is a space, then we will check if the current word is larger than the largest word found so far. If yes, then we will update the largest word.
// 5. finally, we will check the last word and return the largest word found.
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