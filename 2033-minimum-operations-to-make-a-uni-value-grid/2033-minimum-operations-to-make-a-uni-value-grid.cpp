class Solution {
public:
    int minOperations(vector<vector<int>>& A, int x) {
        vector<int> B;
        int res = 0, n = A.size(), m = A[0].size();
        for(auto& row : A) for(auto& col : row) B.push_back(col);
        sort(begin(B), end(B));
        int median = B[B.size() / 2];
        for(auto& b : B) {
            int diff = abs(b-median);
            if(diff % x) return -1;
            res += diff / x;
        }
        return res;
    }
};