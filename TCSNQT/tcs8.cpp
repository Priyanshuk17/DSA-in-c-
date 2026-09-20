#include<bits/stdc++.h>
using namespace std;

// void printFrequency(string &str) {
//     int freq[26] = {0};
//     for(int i=0;i<str.length();i++) {
//         freq[str[i] - 'a']++;
//     }
//     for(int i=0;i<26;i++) {
//         if(freq[i] != 0) {
//             cout << (char)(i + 'a') << freq[i] << " ";
//         }
//     }
// }

// void printFreq(string &str ) {
//     int freq[26] = {0};
//     for(int i=0;i<str.length();i++) {
//         freq[str-'a']++;
//     }
//     for(int i=0;i<freq.size();i++) {
//         if(freq[i]!=0) {
//             cout << (char)(i + 'a') << freq[i] << " ";
//         }
//     }
// }

string nonRepeating(string &s) {
    string res = "";
    int freq[26] = {0};
    for(int i=0;i<s.length();i++) {
        freq[s[i] - 'a']++;
    }
    for(int i=0;i<26;i++) {
        if(freq[i] == 1) {
            res+=(char)(i + 'a');
        }
    }
    return res;
}
int main()
{
  string str = "google"; // Input string
  string res = nonRepeating(str);         // Call the function
  cout << res;
  return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
//   public:

//     // Method to find and print non-repeating characters
//     void nonRepeating(string & st, int freq[200]) {
//         int i, j;
//         // Get the length of the string
//         int l = st.length();  
//         // Count frequency of each character
//         for (int i = 0; i < l; i++) {
//             if (st[i] == ' ')  // Ignoring spaces in the string
//                 continue;
//             else
//                 // Incrementing each character's frequency
//                 freq[st[i] - 'a']++;  
//         }
//         // Print non-repeating characters
//         for (int i = 0; i < l; i++) {
//             if (freq[st[i] - 'a'] == 1 && st[i] != ' ') {
//                 // Output the non-repeating character
//                 cout << st[i] << " ";  
//             }
//         }
//     }
// };

int main() {

    // Input string
    // string st = "blockchain technology";  

    // // Get the length of the string
    // int l = st.length();  

    // // Initialize frequency array
    // int freq[200] = {0};  

    // Solution obj;
    
    // // Print message
    // cout << "Non-Repeating characters: ";  

    // // Call the method to print non-repeating characters
    // obj.nonRepeating(st, freq);  

    return 0;
}