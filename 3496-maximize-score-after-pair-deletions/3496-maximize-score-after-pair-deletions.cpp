class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size(), remain = nums.size() % 2 ? 1 : 2;
        int sum = accumulate(begin(nums), end(nums), 0), res = INT_MIN;
        for(int i = 0; i <= n - remain; i++) {
            int sub = accumulate(begin(nums) + i, begin(nums) + i + remain, 0);
            res = max(res, sum - sub);
        }
        return res;
    }
};