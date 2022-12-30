class Solution {
    vector<vector<int>> res;
    void backtracking(vector<vector<int>>&g, int c, vector<int>& tmp) {
        if(c + 1 == g.size()) {
            res.push_back(tmp);
            return;
        }
        for(auto nxt : g[c]) {
            tmp.push_back(nxt);
            backtracking(g,nxt,tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> tmp{0};
        backtracking(graph,0,tmp);
        return res;
    }
};