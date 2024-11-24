class Solution {
public:
    long long shiftDistance(string initialWord, string finalWord, vector<int>& nextCost, vector<int>& previousCost) {
        vector<vector<long long>> cost(26, vector<long long>(26, 1ll<<48));
        for(int i = 0; i < 26; i++) {
            cost[i][(i+1)%26] = nextCost[i];
            cost[i][(i+25)%26] = previousCost[i];
            cost[i][i] = 0;
        }
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
        long long res = 0;
        for(int i = 0; i < initialWord.size(); i++) {
            res += cost[initialWord[i]-'a'][finalWord[i]-'a'];
        }
        return res;
    }
};