class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0;
        vector<int> best;
        for(auto& c : costs) {
            res += c[0];
            best.push_back(c[1] - c[0]);
        }
        sort(begin(best), end(best));
        for(int i = 0; i < best.size() / 2; i++) res += best[i];
        return res;
    }
};