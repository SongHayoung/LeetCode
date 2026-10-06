
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> pre{{0, -1}};
        unordered_map<int, int> at;
        auto check = [&](int lookup, int pos) {
            return at.count(lookup) and at[lookup] > pos;
        };
        for (int i = 0; i < nums.size(); i++) {
            int x = (nums[i] % k + k) % k;
            sum = (sum + x) % k;
            at[x] = i;

            if (pre.contains(sum))
                res = max(res, i - pre[sum]);
            else
                pre[sum] = i;

            for (auto& [p, pos] : pre) {
                int d = (sum - p + k) % k;

                if (k & 1) {
                    if(check(1ll * d * ((k + 1) / 2) % k, pos))
                        res = max(res, i - pos);
                } else {
                    if (d & 1) continue;
                    if(check(d / 2, pos) or check(d / 2 + k / 2, pos))
                        res = max(res, i - pos);
                }
            }
        }

        return res;
    }
};