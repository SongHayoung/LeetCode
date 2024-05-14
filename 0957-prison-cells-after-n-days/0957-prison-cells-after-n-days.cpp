class Solution {
    bool bit(int x, int p) {
        return (x>>p) & 1;
    }
    bool check(int x, int p) {
        if(p == 0 or p == 7) return false;
        return bit(x,p-1) == bit(x,p+1);
    }
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<int, int> dp;
        int val = 0;
        for(int i = 0; i < 8; i++) {
            if(cells[i]) val ^= 1ll<<i;
        }
        dp[val] = 0;
        for(int i = 1; i <= n; i++) {
            int now = 0;
            for(int i = 1; i < 7; i++) {
                if(check(val,i)) now ^= 1ll<<i;
            }
            if(!dp.count(now)) dp[now] = i;
            else {
                int diff = i - dp[now];
                int rem = (n - i) / diff * diff;
                i += rem;
                dp = {};
            }
            val = now;
        }
        vector<int> res(8);
        for(int i = 0; i < 8; i++) if(bit(val,i)) res[i] = 1;
        return res;
    }
};