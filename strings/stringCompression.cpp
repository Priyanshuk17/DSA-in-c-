#include<bits/stdc++.h>
using namespace std;

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