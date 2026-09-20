#include<bits/stdc++.h>
using namespace std;

void HighestRepeatedLetters(string &str) {
    int len = str.length();
    // Initialize variables for tracking the maximum number of repeated letters
    int maximumword = 0;
    int curr_maximumword = 0;
    string result = "";
    // Iterate through each word in the string
    for (int left = 0; left < len;) {
        // Find the right end of the current word
        int right = left + 1;
        while (str[right] != ' ' && right < len) {
            right++;
        }
        int frequency[26] = {0};  // Frequency array for counting letter occurrences
        curr_maximumword = 0;

        // Count the frequency of each letter in the word
        for (int index = left; index < right; index++) {
            frequency[str[index] - 'a']++;
        }

        // Count the number of repeated letters in the word
        for (int index = 0; index < 26; index++) {
            if (frequency[index] > 1) {
                curr_maximumword++;
            }
        }
        // Update the result if the current word has more repeated letters
        if (curr_maximumword > maximumword) {
            maximumword = curr_maximumword;
            result = "";
            for (int j = left; j < right; j++) {
                result += str[j];
            }
        }
        // Move to the next word
        left = right + 1;
    }
    // If no word with repeated letters is found, print "-1"
    if (result.empty()) {
        cout << "-1";
    }
    else {
        cout << "Word with highest number of repeated letters: ";
        cout << result << "\n";
    }
}
int main() {
    string s;
    getline(cin, s);
    HighestRepeatedLetters(s);

    return 0;
}