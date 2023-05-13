class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        sort(begin(nums), end(nums));
        long long res = 0, mod = 1e9 + 7, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            long long ma = 1ll * nums[i] * nums[i] % mod;
            if(i >= 2) sum = (sum + nums[i-2]) % mod * 2 % mod;
            long long x = (sum + nums[i] + (i ? nums[i-1] : 0)) % mod;
            res = (res + ma * x % mod) % mod;
        }
        return res;
    }
};