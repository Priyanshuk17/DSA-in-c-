#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
    vector<int> prices;
public: 
    StockSpanner() {}

    int next(int price) {
        prices.push_back(price);
        int cnt = 1;

        for(int i = prices.size() - 2; i >= 0;i--) {
            if(prices[i] <= price)
                cnt++;
            else 
                break;
        }
        return cnt;
    }
};

int main() {
    StockSpanner sp;
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};

    for(int x : arr){
        cout << sp.next(x) << " ";
    }
    return 0;
}