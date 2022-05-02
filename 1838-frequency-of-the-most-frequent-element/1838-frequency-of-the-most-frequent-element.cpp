class Solution {
public:
    int maxFrequency(vector<int>& nums, long k) {
        sort(nums.begin(), nums.end());
        long end = 0, sz = nums.size(), res = 0;
        for(int front = 0; front < sz && end < sz; front++) {
            while(end < sz && k >= 0) {
                res = max(res, end - front + 1);
                end++;
                if(end != sz)
                    k -= (end - front) * (nums[end] - nums[end - 1]);
            }
            if(end != sz)
                k += (nums[end] - nums[front]);
        }
        return res;
    }
};