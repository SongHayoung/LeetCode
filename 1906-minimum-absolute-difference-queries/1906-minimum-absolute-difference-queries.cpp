class Solution {
    int psum[101010][101] = {};
public:
    vector<int> minDifference(vector<int>& A, vector<vector<int>>& Q) {
        int n =A.size();
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= 100; j++) {
                psum[i+1][j] = psum[i][j] + (A[i] == j);
            }
        }
        vector<int> res;
        
        for(auto& q : Q) {
            int mi = INT_MAX, last = 0, l = q[0], r = q[1];
            for(int i = 1; i <= 100; i++) {
                if(psum[r+1][i] - psum[l][i]) {
                    mi = min(mi, last ? i - last : INT_MAX);
                    last = i;
                }
            }
            res.push_back(mi == INT_MAX ? -1 : mi);
        }
        
        
        return res;
    }
};