class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        vector<int> heap;
        for(auto& a : arr) ++m[a];
        transform(m.begin(), m.end(), std::back_inserter(heap), [](const pair<int, int> &p) { return p.second; } );
        make_heap(begin(heap), end(heap), greater<int>());
        while(k > 0) {
            k -= heap.front();
            pop_heap(begin(heap), end(heap), greater<int>());
            heap.pop_back();
        }
        return k & (~k + 1) ? heap.size() + 1: heap.size();
    }
};