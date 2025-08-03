
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long n = nums.size(), res = LLONG_MIN;
        vector<long long> pre{0};
        for(int i = 0; i < n; i++) pre.push_back(pre.back() + nums[i]);
        auto qry = [&](long long l, long long r) {
            return pre[r+1] - pre[l];
        };
        vector<array<long long,3>> inc;
        for(int i = 0; i < n - 1; i++) {
            int j = i + 1;
            if(nums[j] <= nums[i]) continue;
            inc.push_back({i,i,nums[i]});
            while(j < n and nums[j] > nums[j-1]) {
                inc.back()[1] = j;
                inc.back()[2] += nums[j];
                j++;
            }
            i = j - 1;
        }
        auto dec = [&](long long l, long long r) {
            for(int i = l; i < r; i++) {
                if(nums[i] <= nums[i+1]) return false;
            }
            return true;
        };
        for(int i = 0; i < inc.size() - 1; i++) {
            if(!dec(inc[i][1], inc[i+1][0])) continue;
            auto [l,r,_] = inc[i];
            long long now = nums[r] + nums[r-1], best = now;
            r -= 2;
            while(r >= l) {
                now += nums[r--];
                best = max(best, now);
            }
            
            long long suf = qry(inc[i][1] + 1, inc[i+1][1]);
            now = suf;
            auto [le, ri, __] = inc[i+1];
            while(le + 1 < ri) {
                now -= nums[ri--];
                suf = max(suf, now);
            }
            res = max(res, best + suf);
        }
        return res;
    }
};