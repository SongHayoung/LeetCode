class Solution {
public:
    int countArrays(vector<int>& digitSum) {
        vector<vector<int>> cands(51);
        auto sumOf = [&](int x) {
            int res = 0;
            while(x) {
                res += x % 10;
                x /= 10;
            }
            return res;
        };
        for(int i = 0; i <= 5000; i++) {
            cands[sumOf(i)].push_back(i);
        }
        long long mod = 1e9 + 7, res = 0;
        vector<pair<int,long long>> dp{{-1,1}};
        for(auto& d : digitSum) {
            long long sum = 0, idx = 0, n = dp.size();
            vector<pair<int,long long>> dpp;
            for(auto& val : cands[d]) {
                while(idx < n and dp[idx].first <= val) {
                    sum = (sum + dp[idx].second) % mod;
                    idx++;
                }
                if(sum) {
                    dpp.push_back({val, sum});
                }
            }
            swap(dp,dpp);
        }
        for(auto& [k,v] : dp) {
            res = (res + v) % mod;
        }
        return res;
    }
};