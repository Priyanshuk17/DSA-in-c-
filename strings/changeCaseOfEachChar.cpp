#include<bits/stdc++.h>
using namespace std;


// this question is to change the case of each character in a string.
// how to do it:-
// 1. take the string as input.
// 2. iterate through the string and check the ascii value of each character.
// 3. if the ascii value is between 65 and 90, then it is an uppercase character, so we will change it to lowercase by adding 32 to its ascii value.
// 4. if the ascii value is between 97 and 122, then it is a lowercase character, so we will change it to uppercase by subtracting 32 from its ascii value.
// 5. finally, print the changed string.
void change(string &s) {
    int n = s.length();
    for(int i=0;i<n;i++) {
        int ascii = (int)s[i];
        if(ascii >= 65 && ascii <= 90) {
            s[i] = ((char) (ascii + 32));
        }
        else if(ascii >= 97 && ascii <= 122) {
            s[i] = ((char) (ascii - 32));
        }
    }
    cout << "After changing:- " << s;
}

int main() {
    string s;
    getline(cin, s);
    change(s);
    return 0;
}