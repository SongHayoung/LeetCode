class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        map<long long, long long> ms;
        for(int i = x; i < nums.size(); i++) ms[nums[i]] += 1;
        long long res = INT_MAX;
        for(int i = 0; ms.size(); i++) {
            auto it = ms.lower_bound(nums[i]);
            if(it != end(ms)) res = min(res, abs(nums[i] - it->first));
            if(it != begin(ms)) res = min(res, abs(nums[i] - prev(it)->first));
            if(--ms[nums[i+x]] == 0) ms.erase(nums[i+x]);
        }
        return res;
    }
};
