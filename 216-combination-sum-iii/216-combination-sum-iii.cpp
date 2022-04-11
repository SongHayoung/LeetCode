class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(k,n,res,tmp,1);
        return res;
    }

    void dfs(int k, int n, vector<vector<int>>& res, vector<int>& tmp, int st) {
        if(!k and !n) res.push_back(tmp);
        if(!k or !n) return;
        int cmp = 0;
        for(int i = 9; i >= st and i > 9 - k; i--) cmp += i;
        if(cmp < n) return;
        for(int i = st; i <= 9 and i <= n; i++) {
            tmp.push_back(i);
            dfs(k-1, n-i, res, tmp, i+1);
            tmp.pop_back();
        }
    }
};