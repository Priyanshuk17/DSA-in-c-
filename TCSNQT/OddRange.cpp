#include<bits/stdc++.h>
using namespace std;

int find(int start, int end) {
    int count = ((end - start)/2) + 1;
    return count;
}

int main() {
    int n = 1;
    int m = 6;
    int res = find(n , m);
    cout << res;
    return 0;
}