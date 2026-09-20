#include<bits/stdc++.h>
using namespace std;

// this question is to print the duplicate characters in a string.
// how to do it:-   
// 1. take the string as input.
// 2. create a frequency array of size 26 and initialize it with 0.
//  3. iterate through the string and for each character, increment its corresponding index in the frequency array. 
// 4. finally, iterate through the frequency array and print the characters that have a frequency greater than 1 along with their frequency.
void printDuplicates(string &s) {
    vector<int> freq(26, 0);
    for(int i=0;i<s.length();i++) {
        freq[s[i]- 'a']++; 
    }
    for(int i=0;i<freq.size();i++) {
        if(freq[i]>1) {
            cout << char(i + 'a') << "-" << freq[i] << "\n";
        }
    }
}
int main() {
    string s;
    getline(cin, s);
    printDuplicates(s);
    return 0;
}