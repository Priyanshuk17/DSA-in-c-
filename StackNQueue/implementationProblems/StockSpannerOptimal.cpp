#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
    stack<pair<int, int>> st; // {price, index}
    int idx;

public:
    StockSpanner() {
        idx = -1;
    }
    int next(int price) {
        idx++;

        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int ans = st.empty() ? (idx + 1) : (idx - st.top().second);
        st.push({price, idx});
        return ans;
    }
    int next(int price) {
        idx++;

        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int ans = st.empty() ? (idx + 1) : (idx - st.top().second);
        st.push({price, idx});
        return ans;
    }
};

int main() {
    StockSpanner sp;
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};

    for(int x : arr) {
        cout << sp.next(x) << " ";
    }

    return 0;
}
