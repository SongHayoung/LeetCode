class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        map<int,set<int>> mp;
        vector<int> fl(nums.size());
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]].insert(i), sum += nums[i];
        vector<long long> res;
        auto mark = [&](int idx) {
            if(fl[idx]) return;
            fl[idx] = true;
            sum -= nums[idx];
            mp[nums[idx]].erase(idx);
            if(mp[nums[idx]].size() == 0) mp.erase(nums[idx]);
        };
        for(auto& q : queries) {
            mark(q[0]);
            while(mp.size() and q[1]--) {
                int idx = *mp.begin()->second.begin();
                mark(idx);
            }
            res.push_back(sum);
        }
        return res;
    }
};