#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    // first we find pivot element
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j) {
        while(i<= high-1 && arr[i] <= pivot) {
            i++;
        }
        while(j >= low + 1 && arr[j] > pivot) {
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if(low<high){
        int pIndex = partition(arr, low, high);
        qs(arr, low,pIndex-1);
        qs(arr,pIndex+1,high);
    }
}
vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size()-1);
    return arr;
}
int main() {
    int n;
    cout << "Enter numbers of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<int> sortedArr = quickSort(arr);

    cout << "Sorted array:\n";
    for(int num: sortedArr) {
        cout << num << " "; 
    }
    cout << endl;
    return 0;
}