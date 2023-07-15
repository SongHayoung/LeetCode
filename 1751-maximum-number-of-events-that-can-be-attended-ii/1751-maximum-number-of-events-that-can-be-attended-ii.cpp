class Solution {
    unordered_map<long, int> dp;
    vector<int> bound;
    int solution(vector<vector<int>>& events, int cur, int k) {
        if(k == 1) return events[cur][2];
        if(cur == events.size()) return 0;
        long key = 1l * k * 1e7 + cur;
        if(dp.count(key)) return dp[key];
        
        dp[key] = events[cur][2];
        vector<int> tmp = {events[cur][1]+1, INT_MIN,INT_MIN};
        auto i = lower_bound(events.begin() + cur, events.end(), tmp) - events.begin();
        
        
        int n = events.size();
        for(; i < n; i++) {
            dp[key] = max(dp[key], solution(events, i, k - 1) + events[cur][2]);
        }
        
        return dp[key];
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(),events.end());
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, solution(events,i,k));
        }
        return res;
    }
};