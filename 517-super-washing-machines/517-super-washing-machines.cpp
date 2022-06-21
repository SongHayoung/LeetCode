class Solution {
public:
    int findMinMoves(vector<int>& A) {
        long long sum = accumulate(begin(A), end(A), 0ll), n = A.size();
        if(sum % n) return -1;
        int res = 0, best = sum / n, pass = 0;
        
        for(auto& a : A) {
            pass = a + pass - best;
            res = max({res, abs(pass), a - best});
        }
        return res;
    }
};