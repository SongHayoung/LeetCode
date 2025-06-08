class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        deque<int> mi,ma;
        int at = 0;
        auto push = [&](int pos) {
            while(mi.size() and nums[mi.back()] > nums[pos]) mi.pop_back();
            mi.push_back(pos);

            while(ma.size() and nums[ma.back()] < nums[pos]) ma.pop_back();
            ma.push_back(pos);
        };
        auto pop = [&]() {
            while(mi.size() and ma.size() and nums[ma[0]] - nums[mi[0]] > k) {
                if(mi[0] == at) mi.pop_front();
                if(ma[0] == at) ma.pop_front();
                at++;
            }
        };
        long long n = nums.size(), mod = 1e9 + 7;
        vector<int> pre(n + 2);
        pre[1] = 1;
        for(int i = 1; i <= n; i++) {
            push(i-1);
            pop();
            pre[i+1] = (pre[i] * 2 - pre[at] + mod) % mod;
        }
        return (pre[n] - pre[at] + mod) % mod;
    }
};