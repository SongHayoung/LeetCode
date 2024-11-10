class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        deque<int> dq, dqq;
        for(int i = 0; i < nums.size(); i++) {
            while(dq.size() and nums[dq.back()] >= nums[i]) dq.pop_back();
            while(dq.size() and dq.front() <= i - k) dq.pop_front();
            while(dqq.size() and dqq.front() <= i - 2 * k) dqq.pop_front();
            dq.push_back(i);
            if(dq.size() == k) {
                dqq.push_back(i-k+1);
                if(dqq[0] == i - 2 * k + 1) return true;
            }
        }
        return false;
    }
};