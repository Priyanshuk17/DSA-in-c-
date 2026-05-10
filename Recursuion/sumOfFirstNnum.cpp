#include<iostream>
using namespace std;
// parameterised way
// void func(int i, int sum) {
//     if(i<1) {
//         cout << sum << endl;
//         return;
//     }
//     func(i-1, sum+i);
// }

//functional way
int sum(int n) {
    if( n == 0) { 
        return 0;
    }
    return n + sum(n-1);
}

int main() {
    int n;
    cin >> n;
    //func(n,0);
    cout << sum(n);
    return 0;
}