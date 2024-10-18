class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ma = 0, n = nums.size(), res = 0;
        for(auto& n : nums) ma |= n;
        for(int i = 1; i < (1<<n); i++) {
            int now = 0;
            for(int j = 0; j < n; j++) {
                if(i & (1<<j)) now |= nums[j];
            }
            res += ma == now;
        }
        return res;
    }
};