class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        vector<long long> pre;
        unordered_map<long long, long long> mp;
        for(auto& n : nums) {
            pre.push_back((pre.size() ? pre.back() : 0) + n);
            mp[pre.back()] = pre.size() - 1;
        }
        long long tot = pre.back(), res = INT_MAX;
        for(auto& n : nums) {
            pre.push_back((pre.size() ? pre.back() : 0) + n);
            mp[pre.back()] = pre.size() - 1;
        }
        for(int i = 0; i < nums.size(); i++) {
            long long loop = target / tot * nums.size();
            long long x = target % tot;
        
            if(mp.count(pre[i] + x)) {
                res = min(res, loop + mp[pre[i] + x] - i);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
