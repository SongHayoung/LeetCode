class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n);
        pre.front() = nums.front();
        suf.back() = nums.back();
        for(int i = 1; i < n; i++) pre[i] = pre[i-1] * nums[i];
        for(int i = n - 2; i >= 0; i--) suf[i] = suf[i+1] * nums[i];
        vector<int> res(n);
        res[0] = suf[1];
        res[n-1] = pre[n-2];
        for(int i = 1; i <= n - 2; i++) {
            res[i] = pre[i-1] * suf[i+1];
        }
        return res;
    }
};