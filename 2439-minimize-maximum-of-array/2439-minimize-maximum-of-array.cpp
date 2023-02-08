class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = 0, res = 0, cnt = 0;
        for(auto n : nums) {
            sum += n;
            cnt += 1;
            res = max(res, (sum + cnt - 1) / cnt);
        }
        return res;
    }
};