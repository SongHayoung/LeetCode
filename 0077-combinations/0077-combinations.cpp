class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res,tmp,k,n,1);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& tmp, int k, int n, int i) {
        if(!k) {
            res.push_back(tmp);
            return;
        }
        for(; i <= n - k + 1; i++) {
            tmp.push_back(i);
            dfs(res, tmp, k - 1, n, i + 1);
            tmp.pop_back();
        }
    }
};