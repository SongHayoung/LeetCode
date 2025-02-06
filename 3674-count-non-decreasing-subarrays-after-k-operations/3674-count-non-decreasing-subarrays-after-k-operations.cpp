class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, long long k) {
        deque<array<long long,3>> dq;
        long long res = 0;
        for(int i = nums.size() - 1; i >= 0; i--) {
            int cnt = 1;
            while(dq.size() and dq.front()[2] <= nums[i]) {
                auto [idx, ccnt, val] = dq.front(); dq.pop_front();
                cnt += ccnt;
                k -= ccnt * (nums[i] - val);
            }
            dq.push_front({i,cnt,nums[i]});
            while(k < 0) {
                k += dq.back()[2] - nums[dq.back()[0] + dq.back()[1] - 1];
                if(--dq.back()[1] == 0) dq.pop_back();
            }

            res += dq.back()[0] + dq.back()[1] - i;
        }
        return res;
    }
};