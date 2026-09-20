#include<bits/stdc++.h>
using namespace std;

bool lemonadeExchange(vector<int> &bills) {
    int n = bills.size();
    int five, ten = 0;
    for(int i=0;i<n;i++) {
        if(bills[i] == 5) {
            five++;
        }
        else if(bills[i] == 10) {
            if(five) {
                five--;
                ten++;
            }
            else {
                return false;
            }
        }
        else {
            if(five && ten) {
                five--;
                ten--;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<int> bills = {5, 5, 10, 20};
    int res = lemonadeExchange(bills);
    cout << res;
    return 0;
}