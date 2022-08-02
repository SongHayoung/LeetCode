class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if(cost1 < cost2) return waysToBuyPensPencils(total, cost2, cost1);
        long long res = 0;
        for(int i = 0; i * cost1 <= total; i++) {
            int rem = total - i * cost1;
            res += (rem / cost2) + 1;
        }
        return res;
    }
};