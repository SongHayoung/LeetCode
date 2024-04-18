class Solution {
    void helper(vector<int>& res, int val, int n) {
        for(int i = val == 0 ? 1 : 0; i <= 9; i++) {
            int now = val + i;
            if(now > n) break;
            res.push_back(now);
            helper(res,now * 10,n);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        helper(res,0,n);
        return res;
    }
};