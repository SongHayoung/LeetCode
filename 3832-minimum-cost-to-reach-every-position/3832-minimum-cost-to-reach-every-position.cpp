class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        for(int best = INT_MAX; auto& c : cost) c = best = min(best, c);
        return cost;
    }
};