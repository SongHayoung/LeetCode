class Solution {
    vector<vector<pair<int, int>>> dp;
    pair<int, int> solution(vector<int>& st, int p, bool alice) {
        if(p == st.size()) return {0,0};
        if(dp[alice][p].first != INT_MIN) return dp[alice][p];
        int sum = st[p];
        pair<int,int>& res = dp[alice][p] = solution(st, p+1, !alice);
        if(alice) {
            res.first += sum;
        } else {
            res.second += sum;
        }

        for(int i = p+1; i < st.size() and i <= p + 2; i++) {
            sum += st[i];
            if(alice) {
                auto [nextAlice, nextBob] = solution(st,i+1,!alice);
                int aliceSum = nextAlice + sum;
                if(aliceSum - nextBob > res.first - res.second) {
                    res = {aliceSum, nextBob};
                }
            } else {
                auto [nextAlice, nextBob] = solution(st,i+1,!alice);
                int bobSum = nextBob + sum;
                if(bobSum - nextAlice > res.second - res.first) {
                    res = {nextAlice, bobSum};
                }
            }
        }
        return res;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        dp = vector<vector<pair<int,int>>> (2,vector<pair<int,int>>(stoneValue.size(), {INT_MIN,INT_MIN}));
        auto [aliceSum, bobSum] = solution(stoneValue,0,true);

        return aliceSum > bobSum ? "Alice" : bobSum > aliceSum ? "Bob" : "Tie";
    }
};