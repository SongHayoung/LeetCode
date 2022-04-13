class Solution {
    int dp[1500];
public:
    int lastStoneWeightII(vector<int>& S) {
        bitset<1501> dp{1};
        int sum = 0;
        for(auto& s : S) {
            sum += s;
            for(int i = min(1500, sum); i >= s; i--)
                dp[i] = dp[i] + dp[i-s];
        }
        for(int i = sum / 2; i >= 0; i--) {
            if(dp[i]) return sum - i*2;
        }
        return -1;
    }
};