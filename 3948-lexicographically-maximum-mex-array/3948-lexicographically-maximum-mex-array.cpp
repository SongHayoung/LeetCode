class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        unordered_map<int,deque<int>> at;
        for(int i = 0; i < nums.size(); i++) at[nums[i]].push_back(i);
        vector<int> res;
        int pos = 0;
        while(at.count(0)) {
            int val = 0, now = pos;
            while(at.count(val)) {
                now = max(now, at[val][0]);
                val++;
            }
            res.push_back(val);
            for(; pos <= now; pos++) {
                at[nums[pos]].pop_front();
                if(at[nums[pos]].size() == 0) at.erase(nums[pos]);
            }
        }
        for(; pos < nums.size(); pos++) res.push_back(0);
        return res;
    }
};