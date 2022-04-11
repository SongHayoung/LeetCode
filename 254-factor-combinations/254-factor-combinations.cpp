class Solution {
    vector<vector<int>> res;
    void helper(int n, int pick, vector<int>& ans) {
        if(n == 1) {
            res.push_back(ans);
        } else {
            for(int i = pick; i <= n; i++) {
                if(n % i == 0) {
                    ans.push_back(i);
                    helper(n / i, i, ans);
                    ans.pop_back();
                }
            }
        }
    }
    
public:
    vector<vector<int>> getFactors(int n) {
        helper(n, 2, vector<int>()={});
        res.pop_back();
        return res;
    }
};