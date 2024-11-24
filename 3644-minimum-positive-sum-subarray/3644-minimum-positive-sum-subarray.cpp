class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        long long res = INT_MAX, n = nums.size();
        vector<long long> pre{nums[0]};
        for(int i = 1; i < n; i++) pre.push_back(pre.back() + nums[i]);
        multiset<long long> ms;
        for(int i = n - 1; i >= 0; i--) {
            if(i + r < n) {
                ms.erase(ms.find(pre[i+r]));
            }
            if(i + l - 1 < n) {
                ms.insert(pre[i+l-1]);
            }
            long long x = i ? pre[i-1] : 0;
            auto it = ms.upper_bound(x);
            if(it != end(ms)) {
                res = min(res, *it - x);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};