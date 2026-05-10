#include<bits/stdc++.h>
using namespace std;

// string frequencySort(string s) {
//     vector<int> freq(256, 0);
//     for(char c : s) {
//         freq[c]++;
//     }
//     string ans = "";
//     for(int i = 0;i<s.size();i++) {
//         int maxFreq = 0;
//         char maxChar;
//         // find max frequency character
//         for(int j = 0;j < 256; j++) {
//             if(freq[j] > maxFreq) {
//                 maxFreq = freq[j];
//                 maxChar = char(j);
//             }
//         }
//         // if no character left
//         if(maxFreq == 0) break;

//         // add to answer
//         for(int k = 0;k < maxFreq;k++) {
//             ans += maxChar;
//         }
//         // mark as used
//         freq[maxChar] = 0;
//     }
//     return ans;
// }

// string frequencySort(string s) {
//     // step 1: frequency count 
//     unordered_map<char, int> freq;
//     for(char c : s) {
//         freq[c]++;
//     }
//     // step 2: string ko vector me daal do 
//     vector<char> chars;
//     for(auto &p : freq) {
//         chars.push_back(p.first);
//     }
//     // step 3: sort based on frequency 
//     sort(chars.begin(), chars.end(), [&](chara, char b) {
//         return freq[a] > freq[b];
//     });
//     // step 4: build answer
//     string ans = "";
//     for(char c : chars) {
//         ans.append(freq[c], c);
//     }
//     return ans;
// }
string frequencySort(string s) {
        // step 1: frequency count
    unordered_map<char, int> freq;
    for(char c : s) {
        freq[c]++;
    }
    int n = s.size();
    vector<string> bucket(n+1);
    for(auto &p : freq) {
        char c = p.first;
        int f = p.second;
        bucket[f] += c;
    }
    string ans = "";
    for(int i = n;i>=0;i--) {
        for(char c : bucket[i]) {
            ans.append(i, c); // repeat n times
        }
    }
    return ans;
}
int main() {
    string s = "tree";
    string ans = frequencySort(s);
    cout << ans;

    return 0;
}