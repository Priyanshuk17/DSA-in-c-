#include<bits/stdc++.h>
using namespace std;

// it is also used for diffrent prolems like split array largest sum
// painters problem same code used in these problems
int countStudents(vector<int> &arr, int pages) {
    int students = 1;
    long long pagesStudent = 0;
    for(int i = 0;i<arr.size();i++) {
        if(pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        }
        else {
            students += 1;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low<=high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if(students > n) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    int n,m;
    cout << "Enter number of books: " << endl;
    cin >> m;
    cout << "Enter number of students: " << endl;
    cin >> n;
    vector<int> arr(m);
    cout << "Enter number of pages in each book: \n";
    for(int i = 0;i<m;i++) {
        cin >> arr[i];
    }
    int ans = findPages(arr, n);
    cout << "Minimum number of pages = " << ans << endl;

    return 0;
}