class Solution {
    int dp[301][11];
    int solution(vector<int>& job, int p, int d) {
        if(dp[p][d] != -1) return dp[p][d];
        if(d == 1) return dp[p][d] = *max_element(job.begin() + p, job.end());
        int ma = 0;
        int& res = dp[p][d] = INT_MAX;
        for(int i = p; i <= job.size() - d; i++) {
            ma = max(ma, job[i]);
            res = min(res, solution(job, i+1, d-1) + ma);
        }
        return res;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d) return -1;
        memset(dp,-1,sizeof(dp));
        return solution(jobDifficulty, 0, d);
    }
};