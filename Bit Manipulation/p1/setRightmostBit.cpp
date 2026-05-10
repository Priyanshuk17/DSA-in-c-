#include<bits/stdc++.h>
using namespace std;

int setBit(int n) {
    return n | (n + 1);
}

int main() {
    int n;
    cin >> n;
    cout << setBit(n);

    return 0;
}
