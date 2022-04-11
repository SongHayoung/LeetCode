class Solution {
private:
    const int MOD = 1000000007;

public:
    int maxProfit(vector<int>& inventory, int orders) {
        long long res = 0;
        sort(inventory.begin(), inventory.end());
        int n = lower_bound(inventory.begin(), inventory.end(), inventory.back()) - inventory.begin();

        while(orders) {
            int mul = inventory.size() - n;
            if(n && (inventory[n] - inventory[n - 1]) * mul <= orders) {
                long long diff = inventory[n] - inventory[n - 1];
                orders -= diff * mul;
                res += mul * diff * (2 * inventory[n] - diff + 1)>>1;
                --n;
                while(n && inventory[n - 1] == inventory[n])
                    --n;
            } else {
                long long diff = orders / mul;
                res += (mul * diff * (2 * inventory[n] - diff + 1)>>1) + (inventory[n] - diff) * (orders % mul);
                return res % MOD;
            }
            res %= MOD;
        }

        return res;
    }
};
