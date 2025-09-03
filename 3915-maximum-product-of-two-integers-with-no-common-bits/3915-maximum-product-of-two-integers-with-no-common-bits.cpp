class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int ma = *max_element(begin(nums), end(nums));
        int bit = ma ? 32 - __builtin_clz(ma) : 1;
        int mask = 1<<bit;
        vector<int> bits(mask);
        for(auto& n : nums) bits[n] = 1;
        long long res = 0;
        for(long long i = mask - 1; i; i--) {
            if(!bits[i]) continue;
            long long until = res / i;
            if(until >= i) break;
            for(long long inv = (mask - 1) ^ i, sub = inv; sub > until; sub = (sub - 1) & inv) {
                if(!bits[sub]) continue;
                res = sub * i;
                break;
            }
        }
        return res;
    }
};