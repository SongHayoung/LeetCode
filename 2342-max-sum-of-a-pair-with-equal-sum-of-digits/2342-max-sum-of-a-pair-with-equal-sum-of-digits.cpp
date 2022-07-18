class Solution {
    int digitSum(int n) {
        int res = 0;
        while(n) {
            res += (n%10);
            n /= 10;
        }
        return res;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int res = -1;
        for(auto& n : nums) {
            mp[digitSum(n)].push_back(n);
        }
        for(auto [_ , v] : mp) {
            if(v.size() == 1) continue;
            sort(begin(v), end(v));
            int sz = v.size();
            res = max(res, v[sz-1] + v[sz-2]);
        }
        return res;
    }
};