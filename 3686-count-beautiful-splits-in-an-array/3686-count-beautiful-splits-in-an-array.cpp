class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int res = 0, n = nums.size();
        unordered_set<long long> matched;
        vector<long long> hashs(n), pre(n + 1);
        long long mod = 1e9 + 7, po = 222, inv = 436936940;
        for(int i = 0; i < n; i++) pre[i+1] = (pre[i] * po + nums[i]) % mod;
        for(long long len = 1, ppo = po, invv = inv; len < n; len++, ppo = ppo * po % mod, invv = invv * inv % mod) {
            for(int i = 0; i < n; i++) {
                if(i + 1 >= len) {
                    hashs[i+1-len] = (pre[i+1] - pre[i+1-len] * ppo % mod + mod) % mod * invv % mod;
                    if(matched.count(i+1-2*len)) continue;
                    if(i + 1 - 2 * len >= 0 and hashs[i+1-len] == hashs[i+1-2*len]) {
                        if(i + 1 - 2 * len == 0) {
                            matched.insert(i + 1 - len);
                            res += n - i - 1;
                        } else res++;
                    }
                }
            }
        }
        return res;
    }
};