class Solution {
    int sum(int x) {
        int res = 0;
        while(x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        int res = -1;
        for(auto& x : nums) {
            int now = sum(x);
            if(mp.count(now)) {
                res = max(res, mp[now] + x);
            }
            mp[now] = max(mp[now], x);
        }
        return res;
    }
};