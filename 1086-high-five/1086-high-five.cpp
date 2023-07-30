class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, vector<int>> best;
        for(auto item : items) {
            best[item[0]].push_back(item[1]);
            sort(rbegin(best[item[0]]), rend(best[item[0]]));
            if(best[item[0]].size() > 5) best[item[0]].pop_back();
        }
        vector<vector<int>> res;
        for(auto [k,vec] : best) {
            res.push_back({k, accumulate(begin(vec), end(vec),0)/5});
        }
        sort(begin(res), end(res), [](auto a, auto b) {
            return a[0] < b[0];
        });
        return res;
    }
};