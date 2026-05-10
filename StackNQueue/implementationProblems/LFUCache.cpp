#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    int capacity;
    int minFreq;

    unordered_map<int, pair<int,int>> keyValFreq;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> keyIterator;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyValFreq.find(key) == keyValFreq.end())
            return -1;

        int value = keyValFreq[key].first;
        int freq = keyValFreq[key].second;

        // Remove key from current frequency list
        freqList[freq].erase(keyIterator[key]);

        // If this was the only key with minFreq
        if (freqList[freq].empty() && freq == minFreq)
            minFreq++;

        // Increase frequency
        freq++;
        keyValFreq[key].second = freq;

        // Add key to new frequency list
        freqList[freq].push_back(key);
        keyIterator[key] = --freqList[freq].end();

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyValFreq.find(key) != keyValFreq.end()) {
            // Update value and frequency
            keyValFreq[key].first = value;
            get(key);
            return;
        }

        if (keyValFreq.size() == capacity) {
            // Remove LFU key
            int lfuKey = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            keyValFreq.erase(lfuKey);
            keyIterator.erase(lfuKey);
        }

        // Insert new key
        keyValFreq[key] = {value, 1};
        freqList[1].push_back(key);
        keyIterator[key] = --freqList[1].end();
        minFreq = 1;
    }
};

int main() {
    LFUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);
    cout << cache.get(1) << endl; // 10
    cache.put(3, 30);             // Evicts key 2
    cout << cache.get(2) << endl; // -1
    cout << cache.get(3) << endl; // 30

    return 0;
}