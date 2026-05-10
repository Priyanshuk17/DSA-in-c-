#include<bits/stdc++.h>
using namespace std;

// Stack overflow 
// Basically Segmentation Error
// void print() {
//     cout << 1 << endl;
// }

// int main () {
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif

//     print();

//     return 0;

// }
int cnt = 0;
void print() {
    if(cnt == 4) return;
    cout << cnt << endl;
    cnt++;
    print();
}

int main() {

    print();
    return 0;
    
}