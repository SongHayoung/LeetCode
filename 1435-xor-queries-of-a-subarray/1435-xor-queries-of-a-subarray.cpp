class Solution {
public:
    vector<int> xorQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> pxor = {0};
        for(int i = 0; i < A.size(); i++) {
            pxor.push_back(pxor.back() ^ A[i]);
        }
        vector<int> res;
        for(auto& q : queries) {
            int l = q[0], r = q[1];
            res.push_back(pxor[l] ^ pxor[r+1]);
        }
        return res;
    }
};