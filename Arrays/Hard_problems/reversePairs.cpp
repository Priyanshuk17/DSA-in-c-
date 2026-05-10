#include<bits/stdc++.h>
using namespace std;


int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low; // starting index of left half of arr
    int right = mid+1; // starting index of right half of arr
    int k=0;

    // storing elements in the temporary array in a sorted manner
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]){
            // left is smaller
            temp.push_back(arr[left]);
            left++;
        }
        // right is smaller
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if elements on the left half is still left
    while (left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    // if elements on the right half is still left
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    // transfering all elements from temporary to arr
    for(int i = low;i <= high;i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for(int i = 0;i <= mid; i++) {
        while(right <= high && arr[i] > 2*arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if(low==high) return cnt;
    int mid = (low + high)/2;
    cnt += mergeSort(arr, low,mid); // left half
    cnt += mergeSort(arr, mid+1,high); // right half
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low,mid,high); // merging sorted halves
    return cnt;
}

int team(vector<int> &skill, int n) {
    return mergeSort(skill, 0, n-1);
}



int main() {



    return 0;
}