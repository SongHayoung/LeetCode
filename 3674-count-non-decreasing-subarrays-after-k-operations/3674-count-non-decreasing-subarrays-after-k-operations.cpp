class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long res = 0, n = nums.size(), r = n - 1, now = 0;
        vector<long long> pre{0};
        for(auto& x : nums) pre.push_back(x + pre.back());
        deque<pair<int,int>> dq;
        auto query = [&](long long l, long long r) {
            return (r + 1 - l) * nums[l] - (pre[r+1] - pre[l]);
        };
        for(int i = n - 1; i >= 0; i--) {
            long long ri = i;
            while(dq.size() and nums[dq.back().first] <= nums[i]) {
                auto [l,r] = dq.back(); dq.pop_back();
                now -= query(l,r);
                ri = r;
            }
            now += query(i,ri);
            dq.push_back({i,ri});
            while(now > k) {
                now = now - nums[dq.front().first] + nums[dq.front().second];
                if(--dq.front().second < dq.front().first) dq.pop_front();
            }
            res += dq.front().second + 1 - i;
        }
        return res;
    }
};