class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res,tmp,c,target,0);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& tmp, vector<int>& c, int t, int st) {
        if(!t) {
            res.push_back(tmp);
            return;
        }
        for(int i = st; i < c.size() and c[i] <= t; i++) {
            if(i == st || c[i] != c[i-1]) {
                tmp.push_back(c[i]);
                dfs(res, tmp, c, t - c[i], i+1);
                tmp.pop_back();
            }
        }
    }
};