
class Solution {
public:
    long long minimumReplacement(vector<int>& A) {
        long long res = 0, mi = 1e9, n = A.size();
        for(int i = n - 1; i >= 0; i--) {
            long long now = (A[i] + mi - 1) / mi;
            mi = A[i] / now;
            res += now - 1;
        }
        return res;
    }
};