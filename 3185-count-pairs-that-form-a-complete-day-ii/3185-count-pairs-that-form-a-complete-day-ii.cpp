class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, long long> freq;
        long long res = 0;
        for(auto& h : hours) {
            int t = h % 24, x = (24 - t + 24) % 24;
            res += freq[x];
            freq[t]++;
        }
        return res;
    }
};