class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long> g;
        for(int i = 0, ma = 0; i < nums.size(); i++) {
            ma = max(ma, nums[i]);
            g.push_back(__gcd(nums[i], ma));
        }
        sort(begin(g), end(g));
        int l = 0, r = g.size() - 1;
        long long res = 0;
        while(l < r) {
            res += __gcd(g[l], g[r]);
            l++,r--;
        }
        return res;
    }
};