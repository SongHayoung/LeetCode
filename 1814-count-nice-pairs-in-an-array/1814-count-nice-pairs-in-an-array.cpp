class Solution {
    int reverse(int n) {
        int res = 0;
        while(n) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        return res;
    }
public:
    int countNicePairs(vector<int>& nums) {
        long long res = 0, mod = 1e9 + 7;
        string rev;
        unordered_map<int, int> m;
        for(auto& n : nums) {
            m[n - reverse(n)]++;
        }
        for(auto& [k, v] : m) {
            res = (res + (1ll * v * (v-1) / 2 % mod)) % mod;
        }
        return res;
    }
};