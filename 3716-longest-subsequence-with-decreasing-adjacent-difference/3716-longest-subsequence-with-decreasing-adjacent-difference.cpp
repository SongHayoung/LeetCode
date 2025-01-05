int fenwick[301][303];
void update(int n, int k, int x) {
    while(k < 303) {
        fenwick[n][k] = max(fenwick[n][k], x);
        k += k & -k;
    }
}
int query(int n, int k) {
    int res = 0;
    while(k) {
        res = max(res, fenwick[n][k]);
        k -= k & -k;
    }
    return res;
}
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        memset(fenwick, 0, sizeof fenwick);
        int n = nums.size(), res = 0;
        unordered_set<int> us{nums[0]};
        for(int i = 1; i < n; i++) {
            if(us.count(nums[i])) {
                int now = query(nums[i], 301) + 1;
                res = max(res, now);
                update(nums[i], 301, now);
            }
            for(auto& u : us) {
                if(u == nums[i]) continue;
                int now = query(u, 300 - abs(u - nums[i]) + 1) + 1;
                res = max(res, now);
                update(nums[i], 300 - abs(u - nums[i]) + 1, now);
            }
            
            us.insert(nums[i]);
        }
        return res + 1;
    }
};