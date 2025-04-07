class Solution {
public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if(!sum) return 0;
        if(-sum > k or sum < k) return -1;
        k += 1800;
        if(k < 0) return -1;
        unordered_map<int,unordered_map<int,unordered_set<int>>> dp;
        int res = -1;
        vector<bool> zero(nums.size(), nums.back() == 0);
        for(int i = nums.size() - 2; i >= 0; i--) {
            zero[i] = nums[i] == 0 or zero[i+1];
        }
        for(int i = 0; auto& n : nums) {
            unordered_map<int,unordered_map<int,unordered_set<int>>> dpp;
            if(n <= limit) {
                dpp[n+1800][-1].insert(n);
                if(n + 1800 == k) res = max(res, n);
            }
            for(auto& [sum, subdp] : dp) {
                for(auto& [op, vals] : subdp) {
                    for(auto& v : vals) {
                        int now = sum + op * n;
                        long long p = v * n;
                        if(p <= limit) {
                            dpp[now][-op].insert(p);
                            if(now == k) res = max(res, (int)p);
                        } else if(res == -1 and zero[i]) {
                            dpp[now][-op].insert(limit + 1);
                        }
                        if(v <= limit or (res == -1 and zero[i])) {
                            dpp[sum][op].insert(v);
                        }
                    }
                }
            }
            swap(dp,dpp);
            i++;
        }
        return res;
    }
};
