class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        vector<long long> dp(r + 1);
        unordered_map<int, int> freq;
        for(auto n : nums) freq[n] += 1;
        long long mod = 1e9 + 7, res = 0;
        for(auto& [k,v] : freq) {
            if(k == 0) continue;
            vector<long long> dpp = dp;
            unordered_map<long long, long long> sums;
            unordered_map<long long, deque<long long>> bucs;
            for(int i = k; i <= r; i++) {
                long long x = i % k;
                sums[x] = (sums[x] + dp[i-k]) % mod;
                bucs[x].push_back(dp[i-k]);
                if(bucs[x].size() > v) {
                    sums[x] = (sums[x] - bucs[x].front() + mod) % mod;
                    bucs[x].pop_front();
                }
                dpp[i] = (dpp[i] + sums[x]) % mod;
                if(i % k == 0 and i / k <= v) dpp[i] = (dpp[i] + 1) % mod;
            }
            swap(dp,dpp);
        }
        for(int i = l; i <= r; i++) res = (res + dp[i]) % mod;
        if(freq.count(0)) res = res * (freq[0] + 1) % mod;
        if(l == 0) res = (res + 1 + freq[0]) % mod;
        return res;
    }
};