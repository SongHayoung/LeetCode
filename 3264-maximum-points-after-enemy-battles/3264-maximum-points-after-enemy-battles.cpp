class Solution {
public:
    long long maximumPoints(vector<int>& A, int k) {
        long long res = 0;
        sort(begin(A), end(A));
        if(A[0] > k) return 0;
        while(A.size()) {
            long long x = A.back();
            res += k / A[0];
            k = k % A[0] + x;
            A.pop_back();
        }
        return res;
    }
};