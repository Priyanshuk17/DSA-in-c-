#include<bits/stdc++.h>
using namespace std;

// void print(int n){
//     int i=1;
//     if(i>n) 
//         return; // Base condition
//     else
//         cout << "Priyanshu" << endl;
//     print(n-1);
// }

// int main() {
//     print(5);
//     return 0;
// }

void func(int i, int n) {
    if(i>n) return;
    cout << "Priyanshu" << endl;
    func(i+1, n);
}

int main() {
    int n;
    cin >> n;

    func(1, n);
}