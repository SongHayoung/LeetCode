class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int best = 0;
        for(int i = 1; i < nums.size() - k + 1; i++) {
            if(nums[best] < nums[i]) best = i;
        }
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(nums[best+i]);
        }
        return res;
    }
};