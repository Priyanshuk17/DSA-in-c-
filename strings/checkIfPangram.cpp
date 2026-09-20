#include<bits/stdc++.h>
using namespace std;

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