class Solution {
    long long mod = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        vector<int> modpow{1};
        for(int i = 1; i <= nums.size(); i++) {
            modpow.push_back((modpow.back()<<1)% mod);
        }
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        long long res = 0;
        bool flag = 1;
        for(; r < nums.size() and nums[l] + nums[r] <= target; r++) {}
        r--;
        while(l <= r) {
            if(flag) {
                res = (res + modpow[r-l+1] - 1) % mod;
                for(; l <= r and nums[l] + nums[r] <= target; l++) {}
                flag = 0;
            } else {
                res = (res - modpow[r-l+1] + 1 + mod) % mod;
                for(; l <= r and nums[l] + nums[r] > target; r--) {}
                flag = 1;
            }
        }
        return res % mod;
    }
};