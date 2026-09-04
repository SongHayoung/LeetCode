
class Solution {
public:
    int countSequences(vector<int>& nums, long long k) {
        int c2 = 0, c3 = 0, c5 = 0;
        while(k % 2 == 0) c2++, k /= 2;
        while(k % 3 == 0) c3++, k /= 3;
        while(k % 5 == 0) c5++, k /= 5;
        if(k != 1) return 0;

        map<array<int,3>,int> dp;
        dp[{0,0,0}] = 1;

        for(auto& n : nums) {
            map<array<int,3>,int> dpp;
            int cc2 = 0, cc3 = 0, cc5 = 0;
            int x = n;
            while(x % 2 == 0) cc2++, x /= 2;
            while(x % 3 == 0) cc3++, x /= 3;
            while(x % 5 == 0) cc5++, x /= 5;
            for(auto& [k,v] : dp) {
                auto [c2,c3,c5] = k;

                dpp[{c2,c3,c5}] += v;
                dpp[{c2+cc2,c3+cc3,c5+cc5}] += v;
                dpp[{c2-cc2,c3-cc3,c5-cc5}] += v;
            }
            swap(dp,dpp);
        }

        return dp[{c2,c3,c5}];
    }
};