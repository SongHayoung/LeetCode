long long mod = 1e9 + 7, id = 0;
pair<long long, long long> dp[2020][10][55];
long long binom[111][111];
long long nCr(int n, int r) {
    if(n - r < r) return nCr(n,n-r);
    if(n == r or r == 0) return 1;
    if(binom[n][r]) return binom[n][r];
    return binom[n][r] = (nCr(n-1,r-1) + nCr(n-1,r)) % mod;
}
class Solution {
    vector<int> cnt;
    long long helper(int odd, int even, int val, int sum) {
        if(val == 10) return sum == 1000;
        if(!cnt[val]) return helper(odd,even,val+1,sum);
        if(dp[sum][val][even].first == id) return dp[sum][val][even].second;
        long long res = 0;

        for(int o = max(0, cnt[val] - even); o <= min(odd,cnt[val]); o++) {
            int e = cnt[val] - o;
            long long oc = nCr(odd, o), ec = nCr(even, e);
            res = (res + oc * ec % mod * helper(odd - o, even - e, val + 1, sum + (o - e) * val)) % mod;
        }
        dp[sum][val][even] = {id, res};
        return res;
    }
public:
    int countBalancedPermutations(string num) {
        id++;
        cnt = vector<int>(10);
        for(auto& n : num) cnt[n-'0']++;
        return helper(num.size() / 2, (num.size() + 1) / 2, 0, 1000);
    }
};