class Solution {
    long long helper(int x) {
        if(x == 0) return 0;
        if(x == 2) return 1;
        if(x == 3) return 1;
        if(x == 1) return INT_MAX;
        return min(helper(x - 2), helper(x - 3)) + 1;
    }
    long long best(int x) {
        if(x == 2) return 1;
        if(x == 3) return 1;
        if(x <= 6) return helper(x);
        int rem = x % 6 + 6;
        int res = (x - rem) / 3;
        return res + helper(rem);
    }
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto n : nums) mp[n] += 1;
        int res = 0;
        for(auto& [k,v] : mp) {
            if(v == 1) return -1;
            res += best(v);
        }
        return res;
    }
};