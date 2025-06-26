class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long now = 0, m = 0, n = s.length(), res = 0;

        for(int i = n - 1; i >= 0; i--,m++) {
            if(s[i] == '0') res++;
            else if(m <= 30) {
                if(((1ll<<m) + now) <= k){
                    now += (1ll<<m);
                    res++;
                }
            }
        }

        return res;
    }
};