class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> window;
        for(int i = 0; i < k - 1; i++) {
            while(!window.empty() and nums[window.back()] <= nums[i])
                window.pop_back();
            window.push_back(i);
        }
        for(int i = k - 1; i < nums.size(); i++) {
            if(!window.empty() and window.front() <= i - k) window.pop_front();
            while(!window.empty() and nums[window.back()] <= nums[i])
                window.pop_back();
            window.push_back(i);
            res.push_back(nums[window.front()]);
        }
        return res;
    }
};