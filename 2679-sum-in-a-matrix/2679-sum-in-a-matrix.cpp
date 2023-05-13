class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(auto& n : nums) sort(begin(n), end(n));
        int res = 0, len = 0;
        for(int i = 0; i < nums.size(); i++) len = max(len, (int)nums[i].size());
        for(int i = 0; i < len; i++) {
            int ma = 0;
            for(int j = 0; j < nums.size(); j++) {
                if(nums[j].size() > i) ma = max(ma, nums[j][i]);
            }
            res += ma;
        }
        return res;
    }
};