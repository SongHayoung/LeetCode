class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> exc, cand;
        int n = fronts.size(), res = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(fronts[i] == backs[i]) exc.insert(fronts[i]);
            else {
                cand.insert(fronts[i]);
                cand.insert(backs[i]);
            }
        }
        for(auto n : cand) {
            if(!exc.count(n)) res = min(res, n);
        }
        return res == INT_MAX ? 0 : res;
    }
};