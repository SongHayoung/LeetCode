class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int kk) {
        deque<array<int,3>> dq;
        long long res = 0, k = kk;
        for(int i = nums.size() - 1; i >= 0; i--) {
            int cnt = 1;
            while(dq.size() and dq.front()[2] <= nums[i]) {
                auto [idx, ccnt, val] = dq.front(); dq.pop_front();
                cnt += ccnt;
                k -= ccnt * (1ll * nums[i] - val);
            }
            dq.push_front({i,cnt,nums[i]});
            while(k < 0) {
                int at = dq.back()[0] + dq.back()[1] - 1;
                k += dq.back()[2] - nums[at];
                if(--dq.back()[1] == 0) dq.pop_back();
            }

            res += dq.back()[0] + dq.back()[1] - i;
        }
        return res;
    }
};