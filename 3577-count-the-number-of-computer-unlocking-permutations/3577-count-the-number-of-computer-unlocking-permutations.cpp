class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long mod = 1e9 + 7, res = 1;
        for(int i = 1; i < complexity.size(); i++) {
            if(complexity[i] <= complexity[0]) return 0;
            res = res * i % mod;
        }
        return res;
    }
};
