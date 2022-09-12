class Solution {
public:
    int bagOfTokensScore(vector<int>& A, int power) {
        sort(begin(A), end(A));
        vector<int> psum{0};
        int res = 0, n = A.size(), l = 0, r = n - 1;
        for(int i = 0; i < n; i++)
            psum.push_back(psum.back() + A[i]);
        while(l <= r) {
            if(psum[r + 1] - psum[l] <= power) {
                return max(res, r - l + 1);
            }
            if(psum[r] - psum[l] <= power) {
                return max(res, r - l);
            }
            if(A[l] > power) break;
            power += A[r--] - A[l++];
        }

        if(l <= r and psum[r + 1] - psum[l] <= power)
            res = max(res, r - l + 1);
        return res;
    }
};