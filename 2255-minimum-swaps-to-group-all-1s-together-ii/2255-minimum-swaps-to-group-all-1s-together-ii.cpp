class Solution {
    int helper(vector<int>& A) {
        int res = A.size(), window = accumulate(begin(A), end(A), 0), now = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i]) now++;
            if(i >= window) now -= A[i-window];
            res = min(res, window - now);
        }
        return res;
    }
public:
    int minSwaps(vector<int>& A) {
        int res = helper(A);
        for(auto& n : A) n = !n;
        return min(res, helper(A));
    }
};