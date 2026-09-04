class Solution {
    int LIS(vector<int>& A) {
        vector<int> dp;
        for(auto& n : A) {
            if(dp.size() == 0 or dp.back() < n) dp.push_back(n);
            else *lower_bound(begin(dp), end(dp), n) = n;
        }
        return dp.size();
    }
public:
    int longestSubsequence(vector<int>& nums) {
        int res = 0;
        for(long long bit = 1; bit < 1e9; bit *= 2) {
            vector<int> A;
            for(auto& n : nums) if (n & bit) A.push_back(n);
            res = max(res, LIS(A));
        }
        return res;
    }
};