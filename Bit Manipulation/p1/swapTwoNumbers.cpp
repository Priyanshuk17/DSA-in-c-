#include<bits/stdc++.h>
using namespace std;

pair<int, int> swapNums(int a, int b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return {a, b};
}

int main() {
    int a, b;
    cin >> a >> b;

    pair<int, int> res = swapNums(a, b);

    cout << res.first << " " << res.second;

    return 0;
}