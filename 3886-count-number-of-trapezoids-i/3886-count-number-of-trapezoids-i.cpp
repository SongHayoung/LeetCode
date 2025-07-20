class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,long long> freq;
        for(auto& p : points) freq[p[1]]++;
        long long res = 0, mod = 1e9 + 7, sum = 0;
        for(auto& [_, cnt] : freq) {
            long long now = cnt * (cnt - 1) / 2;
            
            res = (res + sum * now % mod) % mod;
            sum = (sum + now) % mod;
        }
        return res;
    }
};