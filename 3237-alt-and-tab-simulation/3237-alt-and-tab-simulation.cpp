class Solution {
public:
    vector<int> simulationResult(vector<int>& windows, vector<int>& queries) {
        vector<int> res;
        unordered_set<int> seen;
        for(int i = queries.size() - 1; i >= 0; i--) {
            int w = queries[i];
            if(seen.count(w)) continue;
            seen.insert(w);
            res.push_back(w);
        }
        for(int i = 0; i < windows.size(); i++) {
            if(seen.count(windows[i])) continue;
            res.push_back(windows[i]);
        }
        return res;
    }
};