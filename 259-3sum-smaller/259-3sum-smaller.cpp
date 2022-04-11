class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            while(j < k) {
                while(j < k and nums[i] + nums[j] + nums[k] >= target) k--;
                res += k - j;
                j++;
            }
        }
        return res;
    }
};