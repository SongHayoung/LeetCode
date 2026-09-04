
class Solution {
    int helper(int n) {
        int ma = n % 10, mi = n % 10;
        while(n) {
            int d = n % 10; n /= 10;
            ma = max(ma, d);
            mi = min(mi, d);
        }
        return ma - mi;
    }
public:
    int maxDigitRange(vector<int>& nums) {
        int ma = -1, res = 0;
        for(auto& n : nums) {
            int now = helper(n);
            if(now == ma) res += n;
            else if(now > ma) {
                ma = now;
                res = n;
            }
        }
        return res;
    }
};
