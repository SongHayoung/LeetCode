class Solution {
    int helper(vector<int>& nums) {
        int res = 0, n = nums.size();
        if(n == 1) return 1;
        vector<array<int,3>> A{{nums[0] - nums[1], 0, 1}};
        for(int i = 1; i + 1 < n; i++) {
            int diff = nums[i] - nums[i+1];
            if(A.back()[0] == diff) A.back()[2] = i + 1;
            else A.push_back({diff,i,i+1});
        }
        for(int i = 0; i < A.size(); i++) {
            auto [d,l,r] = A[i];
            res = max(res, min(n, r - l + 1));
            if(r != n - 1 or l) res = max(res, r - l + 2);
            if(r + 2 < n and nums[r] - nums[r+2] == 2 * d) {
                res = max(res, r - l + 3);
                for(int j = i + 1; j < A.size(); j++) {
                    auto [dd,ll,rr] = A[j];
                    if(ll > r + 2) break;
                    if(ll == r + 2 and dd == d) {
                        res = max(res, rr - l + 1);
                    }
                }
            }
        }
        return res;
    }
public:
    int longestArithmetic(vector<int>& nums) {
        int res = helper(nums);
        reverse(begin(nums), end(nums));
        res = max(res, helper(nums));
        return res;
    }
};
