class Solution {
    int memo[101010];
    int helper(int n) {
        if(memo[n] != -1) return memo[n];
        int cnt = 0, sum = 0;
        for(int i = 1; i <= sqrt(n) and cnt < 5; i++) {
            if(n % i == 0) {
                cnt++;
                sum += i;
                if(i * i != n and n % (n/i) == 0) {
                    cnt++;
                    sum += n / i;
                }
            }
        }
        if(cnt != 4) sum = 0;
        return memo[n] = sum;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        memset(memo, -1, sizeof memo);
        int res = 0;
        for(auto& n : nums) res += helper(n);
        return res;
    }
};