#include<bits/stdc++.h>
using namespace std;

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