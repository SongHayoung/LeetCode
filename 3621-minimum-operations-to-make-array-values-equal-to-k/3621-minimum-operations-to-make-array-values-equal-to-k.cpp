class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        if (nums[0] < k) return -1;
        int res = 0;
        while(nums.size() and nums.back() > k) {
            int x = nums.back(); 
            res++;
            while(nums.size() and nums.back() == x) nums.pop_back();
        }
        return res;
    }
};