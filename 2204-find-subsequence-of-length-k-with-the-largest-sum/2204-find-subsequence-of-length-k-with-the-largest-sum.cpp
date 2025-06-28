class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ord(n);
        iota(begin(ord), end(ord), 0);
        sort(begin(ord), end(ord), [&](int i, int j) {
            return nums[i] > nums[j];
        });
        sort(begin(ord), begin(ord) + k);
        vector<int> res;
        for(int i = 0; i < k; i++) res.push_back(nums[ord[i]]);
        return res;
    }
};