class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int res = -1, cnt = -1;
        for(auto d : divisors) {
            int now = 0;
            for(auto n : nums) if(n % d == 0) now += 1;
            if(cnt < now) {
                cnt = now, res = d;
            } else if(cnt == now) {
                res = min(res, d);
            }
        }
        return res;
    }
};

