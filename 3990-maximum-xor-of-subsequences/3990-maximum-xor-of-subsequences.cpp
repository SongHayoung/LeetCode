class Solution {
    bool BIT(int x, int i) {
        return (x>>i) & 1;
    }
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<long long> basis(32);
        auto insert = [&](long long x) {
            for(int i = 31; i >= 0; i--) {
                if(!BIT(x,i)) continue;
                if(!basis[i]) {
                    basis[i] = x;
                    return;
                }
                x ^= basis[i];
            }
            return;
        };
        for(auto& n : nums) insert(n);
        int res = 0;
        for(int i = 31; i >= 0; i--) {
            if(!BIT(res,i)) res ^= basis[i];
        }
        return res;
    }
};