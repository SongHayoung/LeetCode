class Solution {
    vector<int> dp;
    vector<int> bound;
    int solution(vector<array<int,3>>& info, int c) {
        if(dp[c]) return dp[c];
        array<int,3> tmp = {info[c][1],INT_MIN,INT_MIN};
        auto i = lower_bound(info.begin() + c, info.end(), tmp) - info.begin();
        
        dp[c] = info[c][2];
        bound[c] = i;
        int ma = info.size();
        for(; i < ma; i++) {
            dp[c] = max(dp[c], solution(info,i) + info[c][2]);
            ma = min(ma, bound[i]);
        }
        return dp[c];
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        dp = vector<int>(n, 0);
        bound = vector<int>(n, -1);
        vector<array<int,3>> info;
        
        for(int i = 0; i < n; i++) {
            info.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(info.begin(), info.end());
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, solution(info, i));
            n = min(n,bound[i]);
        }
        return res;
    }
};