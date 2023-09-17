class Solution {
    long long helper(long long k) {
        long long res = 1;
        for(int i = 2; i * i <= k; i++) {
            if(k % i) continue;
            int cnt = 0;
            while(k % i == 0) {
                k /= i, cnt += 1;
            }
            if(cnt & 1) res *= i;
        }
        if(k != 1) res *= k;
        return res;
    }
public:
    long long maximumSum(vector<int>& nums) {
        unordered_map<long long, long long> mp;
        long long res = 0;
        for(int i = 0; i < nums.size(); i++) {
            long long k = helper(i + 1);
                mp[k] += nums[i];
                res = max(res, mp[k]);
        }
        return res;
    }
};
