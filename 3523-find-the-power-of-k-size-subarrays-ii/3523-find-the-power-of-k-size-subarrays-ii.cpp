class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            while(dq.size() and dq.back().second != nums[i] - 1) dq.pop_back();
            dq.push_back({i,nums[i]});
            while(dq.size() and dq.front().first <= i - k) dq.pop_front();
            if(i >= k - 1) {
                if(dq.size() == k) res.push_back(nums[i]);
                else res.push_back(-1);
            }
        }
        return res;
    }
};