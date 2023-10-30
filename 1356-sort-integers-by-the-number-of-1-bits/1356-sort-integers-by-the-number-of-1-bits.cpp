class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto compare = [](int a, int b) {
            int bpca = __builtin_popcount(a);
            int bpcb = __builtin_popcount(b);
            return bpca == bpcb ? a < b : bpca < bpcb;
        };
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};