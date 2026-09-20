#include<bits/stdc++.h>
using namespace std;

// this question is to check if a given string is a pangram or not.
// how to do it:-
// 1. take the string as input.
// 2. create a frequency array of size 26 and initialize it with 0.
// 3. iterate through the string and for each character, increment its corresponding index in the frequency array.
// 4. finally, check if all the elements in the frequency array are greater than 0. If yes, then the string is a pangram, otherwise it is not.
bool checkIfPangram(string sentence) {
    vector<int> freq(26, 0);
    for(char c : sentence) {
        freq[c - 'a']++;
    }
    for(int i=0;i<freq.size();i++) {
        if(freq[i]==0) {
            return false;
        }
    }
    return true;
}

int main() {
    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    bool check = checkIfPangram(sentence);
    cout << check;

    return 0;
}