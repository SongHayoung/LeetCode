long long XOR[1<<19], AND[1<<19];

class Solution {
    bool on(int bit, int b) {
        return (bit>>b)&1;
    }
public:
    long long maximizeXorAndXor(vector<int>& nums) {
        int n = nums.size(), limit = 1<<n;
        AND[0] = INT_MAX;
        for(int mask = 1; mask < limit; mask++) {
            int bit = __builtin_ctz(mask);
            XOR[mask] = XOR[mask ^ (1<<bit)] ^ nums[bit];
            AND[mask] = AND[mask ^ (1<<bit)] & nums[bit];
        }
        AND[0] = 0;
        long long full = XOR[limit-1], res = 0;
        for(int mask = 0; mask < limit; mask++) {
            long long sub = full ^ XOR[mask], inv = ~sub, imask = (limit - 1) ^ mask;
            int basis[30] = {};
            for(int i = 0; i < n; i++) {
                if(!on(imask,i)) continue;
                int v = nums[i] & inv;
                for(int b = 29; b >= 0; b--) {
                    if(!on(v,b)) continue;
                    if(!basis[b]) {
                        basis[b] = v;
                        break;
                    }
                    v ^= basis[b];
                }
            }
            long long best = 0;
            for(int b = 29; b >= 0; b--) {
                best = max(best, best ^ basis[b]);
            }
            res = max(res, AND[mask] + 2 * best + sub);
        }
        return res;
    }
};