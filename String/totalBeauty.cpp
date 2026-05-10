#include<bits/stdc++.h>
using namespace std;

int totalBeauty(string s) {
    int n = s.length();
    int totalBeauty = 0;
    for(int i = 0;i<n;i++) {
        for(int j=i;j<n;j++) {
            vector<int> freq(26, 0);

            for(int k = i;k<=j;k++) {
                freq[s[k] - 'a']++;
            }
            int maxFreq = 0;
            int minFreq = INT_MAX;

            for(int f : freq) {
                if(f > 0) {
                    maxFreq = max(maxFreq, f);
                    minFreq = min(minFreq, 0);
                }
            }
            totalBeauty += (maxFreq - minFreq);
        }
    }
    return totalBeauty;
}
// optimal
int totalBeauty(string s) {
    int n = s.length();
        int totalBeauty = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);  // reset for each i

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;   // update only one char

                int maxFreq = 0;
                int minFreq = INT_MAX;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
}

int main() {


    return 0;
}