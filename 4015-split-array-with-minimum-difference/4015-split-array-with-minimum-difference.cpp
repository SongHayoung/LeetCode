class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> inc(n, false), dec(n, false);
        inc[0] = dec[n-1] = true;
        for(int i = 1; i < n and inc[i-1]; i++) inc[i] = nums[i-1] < nums[i];
        for(int i = n - 2; i >= 0 and dec[i+1]; i--) dec[i] = nums[i] > nums[i+1];
        long long res = LLONG_MAX;
        vector<long long> pre{0};
        for(int i = 0; i < n; i++) pre.push_back(pre.back() + nums[i]);
        auto qry = [&](int l, int r) {
            return pre[r+1] - pre[l];
        };
        for(int i = 0; i < n - 1; i++) {
            if(inc[i] and dec[i+1]) res = min(res, abs(qry(0,i) - qry(i+1, n-1)));
        }
        return res == LLONG_MAX ? -1 : res;
    }
};