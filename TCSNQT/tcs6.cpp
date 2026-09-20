#include<bits/stdc++.h>
using namespace std;

int sumOfNumbersInString(string &s) {
    string temp = "";
    int sum = 0;
    for(char c : s) {
        if(isdigit(c)) {
            temp+=c;
        }
        else {
            if(!temp.empty()) {
                sum += stoi(temp);
                temp = "";
            }
        }
    }
    if(!temp.empty()) {
        sum += stoi(temp);
    }
    return sum;
}

int main() {
    string s = "1xyz23";
    int res = sumOfNumbersInString(s);
    cout << res;

    return 0;
}