class Solution {
public:
    int numSub(string s) {
        int cnt = 0, res = 0, mod = 1e9 + 7;
        for(auto& c : s) {
            if(c == '1') cnt++;
            else {
                res = (res + (cnt + 1) * 1l * cnt / 2 % mod) % mod;
                cnt = 0;
            }
        }
        res = (res + (cnt + 1) * 1l * cnt / 2 % mod) % mod;
        return res;
    }
};