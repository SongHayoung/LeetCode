class Solution {
public:
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        vector<vector<int>> bits(3,vector<int>(2));
        for(auto& x : a) bits[0][__builtin_popcount(x) % 2]++;
        for(auto& x : b) bits[1][__builtin_popcount(x) % 2]++;
        for(auto& x : c) bits[2][__builtin_popcount(x) % 2]++;
        int res = 0;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    if(1 ^ i ^ j ^ k) res += bits[0][i] * bits[1][j] * bits[2][k];
                }
            }
        }
        return res;
    }
};