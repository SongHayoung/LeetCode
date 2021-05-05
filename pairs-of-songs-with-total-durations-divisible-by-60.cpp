class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> m;
        for(auto& t : time) {
            m[t % 60]++;
        }

        int res = m[0] * (m[0] - 1) / 2 + m[30] * (m[30] - 1) / 2;
        
        for(int i = 1; i <= 29; i++) {
            res += m[i] * m[60 - i];
        }

        return res;
    }
};
