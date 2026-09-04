class Solution {
public:
    long long minMoves(vector<int>& balance) {
        if(accumulate(begin(balance), end(balance), 0ll) < 0) return -1;
        long long res = 0, at = min_element(begin(balance), end(balance)) - begin(balance), n = balance.size(), l = at - 1, r = at + 1, cost = 1;
        while(balance[at] < 0) {
            if(l == -1) l = n - 1;
            if(r == n) r = 0;
            long long req = -balance[at];
            long long op = min(req, 0ll + balance[l] + balance[r]);
            res += op * cost;
            balance[at] += op;
            l--,r++,cost++;
        }
        return res;
    }
};