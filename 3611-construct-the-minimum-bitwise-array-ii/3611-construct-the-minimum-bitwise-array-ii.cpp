class Solution {
    bool bit(int x, int k) {
        return (x>>k) & 1;
    }
    int helper(int x) {
        if(x % 2 == 0) return -1;
        int mask = INT_MAX;
        for(int i = 0; i < 32; i++) {
            if(bit(x,i)) continue;
            return x ^ (1ll<<(i-1));
        }
        return -1;
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for(auto& n : nums) res.push_back(helper(n));
        return res;
    }
};