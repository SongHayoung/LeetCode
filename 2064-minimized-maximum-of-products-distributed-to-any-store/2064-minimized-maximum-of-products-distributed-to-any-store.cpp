class Solution {
    int helper(vector<int>& A, int k) {
        int res = 0;
        for(auto& a : A) {
            res += (a + k - 1) / k;
        }
        return res;
    }
public:
    int minimizedMaximum(int n, vector<int>& A) {
        int l = 1, r = *max_element(begin(A), end(A));
        int res = r;
        while(l <= r) {
            int m = l + (r - l) / 2;
            int req = helper(A, m);
            if(req <= n) {
                res = min(m,res);
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};