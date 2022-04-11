class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                auto bound = prev(lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]));
                auto dis = bound - (nums.begin() + j);
                if(dis > 0) {
                res += dis;
                }
            }
        }
        return res;
    }
};