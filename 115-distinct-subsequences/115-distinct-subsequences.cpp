class Solution {
    unordered_map<char, vector<int>> seq;
    //index of t and select of s
    int dp[1001][1001];
    int ma;
    //o(m*k * logk)
    //m is for iterating all idx
    //logk is for binary search
    //k is for iterating binary search solution
    int solution(string& t, int idx, int mi) {
        if(idx == t.length()) return 1;
        if(dp[idx][mi] != -1) return dp[idx][mi];
        if(t.length() - idx > ma - mi) return 0;
        dp[idx][mi] = 0;
        auto it = lower_bound(seq[t[idx]].begin(), seq[t[idx]].end(), mi);
        for(; it != seq[t[idx]].end(); it++) {
            dp[idx][mi] += solution(t,idx + 1, *it + 1);
        }
        return dp[idx][mi];
    }
public:
    //o(n + kmlogk)
    int numDistinct(string s, string t) {
        for(int i = 0; i < s.length(); i++) { //o(n)
            seq[s[i]].push_back(i);
        }
        memset(dp,-1,sizeof(dp));
        ma = s.length();
        return solution(t,0,0);
    }
};