class Solution {
public:
    int countDistinctStrings(string s, int k) {
        if(s.length() == k) return 2;
        long long res = 1, mod = 1e9 + 7;
        for(int i = 0; i <= s.length() - k; i++) res = res * 2 % mod;
        return res;
    }
};