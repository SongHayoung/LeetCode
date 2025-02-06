class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, long long k) {
        deque<pair<int,int>> dq;
        long long res = 0;
        for(int i = nums.size() - 1; i >= 0; i--) {
            int cnt = 1;
            while(dq.size() and nums[dq.front().first] <= nums[i]) {
                auto [idx, ccnt] = dq.front(); dq.pop_front();
                cnt += ccnt;
                k -= 1ll * ccnt * (nums[i] - nums[idx]);
            }
            dq.push_front({i,cnt});
            while(k < 0) {
                k += nums[dq.back().first] - nums[dq.back().first + dq.back().second - 1];
                if(--dq.back().second == 0) dq.pop_back();
            }
            res += dq.back().first + dq.back().second - i;
        }
        return res;
    }
};