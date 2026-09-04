class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        costBoth = min(costBoth, cost1 + cost2);
        long long res = 1ll * min(need1, need2) * costBoth;
        if(need1 > need2) {
            res += 1ll * (need1 - need2) * min(cost1, costBoth);
        }
        if(need2 > need1) {
            res += 1ll * (need2 - need1) * min(cost2, costBoth);
        }
        return res;
    }
};