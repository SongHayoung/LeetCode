unordered_map<long long, long long> dp[16]; 
class Solution {
    long long helper(string& s, int pos, int sum, bool less) {
        if(pos == s.length()) return sum == 0;
        if(less) {
            if(dp[pos].count(sum)) return dp[pos][sum];
            for(int i = 0; i < 10; i++) {
                dp[pos][sum] += helper(s,pos + 1, sum + i * (pos & 1 ? 1 : -1), less);
            }
            return dp[pos][sum];
        }
        long long res = helper(s, pos + 1, sum + (s[pos] - '0') * (pos & 1 ? 1 : -1), false);
        for(int i = 0; i < s[pos] - '0'; i++) {
            res += helper(s,pos + 1, sum + i * (pos & 1 ? 1 : -1), true);
        }
        return res;
    }
    long long helper(long long n) {
        string s = to_string(n);
        for(int i = 0; i < 16; i++) dp[i].clear();
        return helper(s,0,0,0);
    }
public:
    long long countBalanced(long long low, long long high) {
        return helper(high) - helper(low - 1);
    }
};