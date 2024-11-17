class Solution {
    bool helper(vector<int>& A, vector<vector<int>>& Q, int k) {
        vector<int> pre(A.size() + 1);
        for(int i = 0; i < k; i++) {
            int l = Q[i][0], r = Q[i][1], x = Q[i][2];
            pre[l] += x;
            pre[r+1] -= x;
        }
        for(int i = 0; i < A.size(); i++) {
            if(i) pre[i] += pre[i-1];
            if(A[i] > pre[i]) return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0, r = queries.size(), res = INT_MAX;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(nums, queries, m);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res == INT_MAX ? -1 : res;
    }
};