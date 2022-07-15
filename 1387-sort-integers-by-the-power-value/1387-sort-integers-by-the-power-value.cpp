class Solution {
    unordered_map<int, int> dp;
    int helper(int n) {
        if(dp.count(n)) return dp[n];
        if(n & 1) return dp[n] = 1 + helper(n * 3 + 1);
        return dp[n] = 1 + helper(n / 2);
    }
public:
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int, int>> q;
        dp[1] = 1;
        for(int i = lo; i <= hi; i++) {
            int p = helper(i);
            q.push({p,i});
            if(q.size() > k) q.pop();
        }
        
        return q.top().second;
    }
};