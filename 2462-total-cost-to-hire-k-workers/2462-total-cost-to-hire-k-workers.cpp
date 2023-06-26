class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long res = 0;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
        int l = 0, r = costs.size() - 1;
        for(; l < candidates; l++) q.push({costs[l],l});
        for(; r >= costs.size() -candidates and r >= l; r--) q.push({costs[r], r});
        while(k--) {
            auto [p,idx] = q.top(); q.pop();
            res += p;
            if(l <= r) {
                if(idx < l) {
                    q.push({costs[l],l});
                    l += 1;
                }
                else{
                 q.push({costs[r],r});
                    r -= 1;
                }
            }
        }
        return res;
    }
};
