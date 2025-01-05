class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(begin(coins), end(coins));
        vector<long long> pos;
        for(auto& c : coins) {
            int l = c[0], r = c[1];
            pos.push_back(l);
            pos.push_back(max(1,r - k + 1));
        }
        sort(begin(pos), end(pos));
        pos.erase(unique(begin(pos), end(pos)), end(pos));
        long long l = 0, r = 0, n = coins.size(), tot = 0, res = 0;
        for(auto& p : pos) {
            while(r < n and coins[r][0] <= p + k - 1) {
                tot += 1ll * (coins[r][1] - coins[r][0] + 1) * coins[r][2];
                r++;
            }
            while(l < r and coins[l][1] < p) {
                tot -= 1ll * (coins[l][1] - coins[l][0] + 1) * coins[l][2];
                l++;
            }
            res = max(res, tot - max(0ll, coins[r - 1][1] - (p + k - 1)) * coins[r-1][2] - max(0ll, p - coins[l][0]) * coins[l][2]);
        }
        
        return res;
    }
};