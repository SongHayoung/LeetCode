class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> res;
        for(int i = 0, x = -1, cnt = 0; i < nums.size(); i++) {
            if(x == nums[i]) cnt++;
            else x = nums[i], cnt = 1;
            if(cnt <= k) res.push_back(x);
        }
        return res;
    }
};