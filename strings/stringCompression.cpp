#include<bits/stdc++.h>
using namespace std;

// this question is to compress a string by replacing consecutive repeating characters with the character followed by the count of repetitions.
// how to do it:-       
// 1. take the string as input.
// 2. iterate through the string and for each character, count the number of consecutive repetitions of that character.         
// 3. for each character, if the count of repetitions is greater than 1, we will add the character followed by the count to the result string. If the count is 1, we will just add the character to the result string.      
// 4. finally, return the length of the compressed string.
int compress(vector<char> &chars) {
    int n = chars.size();
    int index = 0;
    int i = 0;
    while(i < n) {
        char curr_char = chars[i];
        int count = 0;
        while(i < n && chars[i] == curr_char) {
            count++;
            i++;
        } 
        chars[index] = curr_char;
        index++;
        if(count > 1) {
            string count_str = to_string(count);
            for(char &ch : count_str) {
                chars[index] = ch;
                index++;
            }
        }
    }
    return index;
}

int main() {
    vector<char> chars = {'a', 'a', 'a', 'b', 'b', 'c', 'd'};
    int res = compress(chars);
    cout << res;
    return 0;
}