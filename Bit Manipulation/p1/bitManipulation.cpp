#include<bits/stdc++.h>
using namespace std;

void bitManipulation(int num, int i) {
    // get the ith bit
    int getBit = (num >> (i - 1) & 1);

    // Set the ith bit
    int setBit = num | (1 << (i - 1));

    // clear the ith bit
    int clearBit = num & ~(1 << (i - 1));

    cout << getBit << " " << setBit << " " << clearBit;
}

int main() {
    int num;
    cin >> num;
    int i;
    cin >> i;
    bitManipulation(num, i);

    return 0;
}