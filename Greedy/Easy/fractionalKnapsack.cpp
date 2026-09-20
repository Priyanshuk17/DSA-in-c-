#include<bits/stdc++.h>
using namespace std;

struct Item {
    int val;
    int wt;
};

bool comp(Item a, Item b) {
    return (double)(a.val / a.wt) > (double)(b.val / b.wt);
}

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity) {
    int n = val.size();

    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        items[i] = {val[i], wt[i]};
    }

    sort(items.begin(), items.end(), comp);
    double ans = 0.0;

    for (int i = 0; i < n; i++) {

        if (items[i].wt <= capacity) {
            ans += items[i].val;
            capacity -= items[i].wt;
        }
        else {
            ans += ((double)items[i].val / items[i].wt) * capacity;
            break;
        }
    }

    return ans;

}

int main() {
    vector<int> val = {60, 100, 200, 100};
    vector<int> wt = {10, 20, 50, 50};
    int capacity = 90;
    double res = fractionalKnapsack(val, wt, capacity);
    cout << res;
}