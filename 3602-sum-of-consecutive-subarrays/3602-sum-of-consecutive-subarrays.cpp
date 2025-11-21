
class Solution {
public:
    int getSum(vector<int>& nums) {
        long long n = nums.size(), mod = 1e9 + 7, res = 0;
        auto calc = [&](int l, int r) {
            long long pre = 0, cnt = 0;
            for(int i = l; i <= r; i++) {
                ++cnt;
                pre = (pre + cnt * nums[i] % mod) % mod;
                res = (res + pre) % mod;
            }
        };
        int i = 0;
        while(i < n) {
            int j = i + 1;
            if(j == n or abs(nums[i] - nums[j]) != 1) {
                res = (res + nums[i]) % mod;
                i++;
            } else {
                int diff = nums[i] - nums[j];
                while(j < n and nums[j-1] - nums[j] == diff) j++;
                calc(i,j-1);
                if(j < n and abs(nums[j-1] - nums[j]) == 1) {
                    res -= nums[j-1];
                    i = j - 1;
                } else i = j;
            }
        }
        return res;
    }
};
