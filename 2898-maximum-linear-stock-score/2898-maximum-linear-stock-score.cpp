class Solution {
public:
    long long maxScore(vector<int>& prices) {
        unordered_map<int, long long> best;
        long long res = 0;
        for(int i = 0; i < prices.size(); i++) {
            res = max(res, (best[prices[i]-i] += prices[i]));
        }
        return res;
    }
};