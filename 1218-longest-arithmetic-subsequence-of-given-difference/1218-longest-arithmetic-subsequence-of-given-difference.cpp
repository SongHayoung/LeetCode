class Solution {
    unordered_map<int, vector<int>> mp;
    vector<int> dp;
    int helper(int num, int pos, int diff) {
        if(dp[pos] != -1) return dp[pos];
        dp[pos] = 1;
        auto& vec = mp[num + diff];
        auto it = upper_bound(begin(vec), end(vec), pos);
        if(it == end(vec)) return dp[pos];
        dp[pos] = 1 + helper(num + diff, *it, diff);
        return dp[pos];
    }
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size(), res = 0;
        dp = vector<int>(n, -1);
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        unordered_set<int> vis;
        for(int i = 0; i < n; i++) {
            if(vis.count(arr[i])) continue;
            vis.insert(arr[i]);
            res = max(res, helper(arr[i], i, difference));
        }
        return res;
    }
};