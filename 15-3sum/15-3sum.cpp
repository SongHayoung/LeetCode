class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        int n = nums.size(), prv = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(prv == nums[i]) continue;
            int l = i + 1, r = n - 1;
            while(l < r) {
                while(nums[l] + nums[r] + nums[i] != 0 and l < r) {
                    if(nums[l] + nums[r] + nums[i] < 0) l++;
                    else r--;
                }
                if(nums[l] + nums[r] + nums[i] == 0 and l != r)
                    res.push_back({nums[i], nums[l], nums[r]});
                l++, r--;
                while(l < r and nums[l] == nums[l-1]) l++;
                while(r > l and nums[r] == nums[r+1]) r--;
            }
            prv = nums[i];
        }
        
        return res;
    }
};