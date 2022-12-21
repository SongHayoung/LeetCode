class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        long long bit[64] = {};
        for(auto n : nums) {
            for(long long b = 0; b < 32; b++) {
                if(n & (1ll<<b)) bit[b] += 1;
            }
        }
        long long res = 0;
        for(int i = 0; i < 64; i++) {
            if(i) bit[i] += bit[i-1] / 2;
            if(bit[i]) res |= (1ll<<i);
        }
        return res;
    }
};