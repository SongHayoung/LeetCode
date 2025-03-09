
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        if(conflictingPairs.size() == 1) return 1ll * n * (n + 1) / 2;
        vector<pair<int,int>> bounds(n+1,{-1,0});
        for(auto& c : conflictingPairs) {
            if(c[0] > c[1]) swap(c[0],c[1]);
            int x = c[0];
            if(bounds[c[1]].second < x) swap(bounds[c[1]].second, x);
            if(bounds[c[1]].first < x) swap(bounds[c[1]].first, x);
        }
        
        sort(begin(conflictingPairs), end(conflictingPairs));
        
        int top1 = n + 1, top2 = n + 1;
        long long tot = 0, best = 0;
        vector<long long> bests(n+1);
        for(int i = n, j = conflictingPairs.size() - 1; i; i--) {
            while(j >= 0 and conflictingPairs[j][0] >= i) {
                int x = conflictingPairs[j--][1];
                if(top2 > x) swap(top2, x);
                if(top1 > x) swap(top1, x);
            }
            tot += top2 - i;
            int at = min(n, top2);
            if(i >= bounds[at].first) {
                best = max(best, bests[at] += top1 - top2);
            }
        }
        return tot + best;
    }
};