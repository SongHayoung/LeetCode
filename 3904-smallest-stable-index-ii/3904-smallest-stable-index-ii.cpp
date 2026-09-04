class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ma(n,nums.front()), mi(n,nums.back());
        for(int i = 1; i < n; i++) ma[i] = max(nums[i], ma[i-1]);
        for(int i = n - 2; i >= 0; i--) mi[i] = min(nums[i], mi[i+1]);
        for(int i = 0; i < n; i++) {
            if(ma[i] - mi[i] <= k) return i;
        }
        return -1;
    }
};