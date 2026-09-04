class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long> sum(26);
        long long total = 0;

        for(int i = 0; i < s.size(); i++) {
            total += cost[i];
            sum[s[i] - 'a'] += cost[i];
        }

        return total - *max_element(sum.begin(), sum.end());
    }
};