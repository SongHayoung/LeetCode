class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long, int> freq;
        unordered_map<long long, int> dp;
        for(auto& n : nums) freq[n] += 1;
        int res = 1;
        if(freq.count(1)) {
            int x = freq[1];
            if(x % 2 == 0) x -= 1;
            res = max(res, x);
        }
        for(auto& [k,v] : freq) {
            if(dp.count(k)) res = max(res, 1 + dp[k]);
            if(v >= 2) {
                long long kk = k * k;
                long long cnt = 2l;
                if(dp.count(k)) cnt += dp[k];
                dp[kk] = cnt;
            }
        }
        return res;
    }
};