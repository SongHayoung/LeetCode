class Solution {
    long long helper(vector<int>& A, int k) {
        long long res = 0;
        for(auto& a : A) {
            res += abs(k - a);
        }
        return res;
    }
public:
    int minMoves2(vector<int>& A) {
        sort(begin(A), end(A));
        int n = A.size(), m = A[n/2];
        int res = 0;
        for(auto& a : A)
            res += abs(m-a);
        return res;
    }
};