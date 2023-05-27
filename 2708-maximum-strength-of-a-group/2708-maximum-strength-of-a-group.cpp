class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long res = 1;
        for(auto n : nums) res *= n;
        for(int i = 1; i < 1<<(nums.size()); i++) {
            long long now = 1;
            for(int j = 0; j < nums.size(); j++) {
                if(i & (1ll<<j)) now *= nums[j];
            }
            res = max(res, now);
        }
        return res;
    }
};