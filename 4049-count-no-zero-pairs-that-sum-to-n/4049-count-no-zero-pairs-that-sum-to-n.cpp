
long long dp[20][2][2][2];
class Solution {
public:
    long long countNoZeroPairs(long long n) {
        vector<int> d;
        while(n) {
            d.push_back(n % 10); n /= 10;
        }
        memset(dp,0,sizeof dp);
        dp[0][0][1][1] = 1;
        for(int pos = 0; pos < d.size(); pos++) {
            for(int carry : {0,1}) for(int a : {0,1}) for(int b : {0,1}) {
                if(!dp[pos][carry][a][b]) continue;
                vector<pair<int,int>> A,B;
                if(!a) A.push_back({0,0});
                else {
                    for(int i = 1; i <= 9; i++) A.push_back({i,1});
                    if(pos) A.push_back({0,0});
                }

                if(!b) B.push_back({0,0});
                else {
                    for(int i = 1; i <= 9; i++) B.push_back({i,1});
                    if(pos) B.push_back({0,0});
                }
                for(auto& [aa,na] : A) for(auto& [bb,nb] : B) {
                    long long now = aa + bb + carry;
                    if(now % 10 != d[pos]) continue;
                    dp[pos+1][now / 10][na][nb] += dp[pos][carry][a][b];
                }
            }
        }

        long long res = 0;
        for(int a : {0,1}) for(int b : {0,1}) res += dp[d.size()][0][a][b];
        return res;
    }
};