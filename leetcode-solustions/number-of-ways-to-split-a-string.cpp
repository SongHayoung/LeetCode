class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int numWays(string s) {
        int len = s.length();
        vector<int> places;
        for(int i = 0; i < len; i++) {
            if (s[i] == '1') {
                places.push_back(i);
            }
        }

        return places.size() % 3 != 0 || len < 3 ? 0 :
        places.empty() ? ((long)(len - 2) * (long)(len - 1) / 2) % MOD :
        ((long)(places[(int)places.size() / 3] - places[(int)places.size() / 3 - 1]) * (long)(places[(int)places.size() / 3 * 2] - places[(int)places.size() / 3 * 2 - 1])) % MOD;
    }
};
