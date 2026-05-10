#include<bits/stdc++.h>
using namespace std;

vector<int> moveZeroes(int n, vector<int> arr) {
    // Brute force approach
    // // step->1
    // vector<int> temp;
    // for(int i=0;i<n;i++) {
    //     if(arr[i] != 0) {
    //         temp.push_back(arr[i]);
    //     }
    // }
    // // step->2
    // int nz = temp.size();
    // for(int i=0;i<nz;i++) {
    //     arr[i] = temp[i];
    // }

    // // step->3
    // for(int i=nz;i<n;i++) {
    //     arr[i] = 0;
    // }
    // return arr;

    // Optimal approach
    // TC-> O(n)
    // SC-> O(1)
    int j = -1;
    for(int i=0;i<n;i++) {
        if(arr[i] == 0) {
            j = i;
            break;
        }
    }
    for(int i=j+1;i<n;i++) {
        if(arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return arr;
}
// most optimal one
// void moveZeroes(vector<int>& nums) {
        
//     //what ?
//     //shift all non element to the left
//     int nonZero = 0;

//     for(int j=0;j<nums.size(); j++) {
//         if(nums[j] != 0) {
//             swap(nums[j], nums[nonZero]);
//             nonZero++;
//         }
//     }
// }

int main() {
    int n;
    cout << "Enter numbers of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<int> moved = moveZeroes(n, arr);

    cout << "Moved array:\n";
    for(int num: moved) {
        cout << num << " "; 
    }
    cout << endl;
    return 0;
}