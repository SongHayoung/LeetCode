class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& A, vector<vector<int>>& Q) {
        vector<int> pre;
        for(int i = 0; i < A.size() - 1; i++) {
            if(pre.size()) pre.push_back(pre.back());
            else pre.push_back(0);
            if((A[i] ^ A[i+1]) % 2 == 0) pre.back() += 1;
        }
        vector<bool> res;
        for(auto& q : Q) {
            int l = q[0], r = q[1];
            if(l == r) res.push_back(true);
            else {
                int x = pre[r-1];
                if(l) x -= pre[l-1];
                res.push_back(x == 0);
            }
        }
        return res;
    }
};
