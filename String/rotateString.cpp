#include<bits/stdc++.h>
using namespace std;


// bool rotateString(string s, string goal) {
//     if (s.length() != goal.length())
//         return false;

//     int n = s.size();
//     for( int i = 0; i < n ; i++ ) {
//         char firstChar = s[0];
//         s = s.substr(1) + firstChar;

//         if(s == goal) {
//             return true;
//         }
//     }
    
//     return false;
// }
bool rotateString(string s, string goal) {
    if(s.size() != goal.size()) return false;

    string temp = s + s;
    return temp.find(goal) != string::npos;
}

int main() {
    string s = "abcde";
    string goal = "cdeab";

    cout << rotateString(s, goal);
    return 0;
}